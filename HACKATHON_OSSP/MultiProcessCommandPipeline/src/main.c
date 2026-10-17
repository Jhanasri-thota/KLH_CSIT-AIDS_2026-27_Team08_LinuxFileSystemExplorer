#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <signal.h>

#define MAX_COMMANDS 20
#define MAX_ARGS 40
#define MAX_INPUT 2048

static void trim(char *s)
{
    char *start = s;

    while (isspace((unsigned char)*start))
        start++;

    if (start != s)
        memmove(s, start, strlen(start) + 1);

    size_t len = strlen(s);

    while (len > 0 && isspace((unsigned char)s[len - 1]))
        s[--len] = '\0';
}

static double elapsed_ms(struct timespec start,
                         struct timespec end)
{
    return (end.tv_sec - start.tv_sec) * 1000.0
         + (end.tv_nsec - start.tv_nsec) / 1000000.0;
}

/* Parse whitespace-separated and quoted arguments. */
static int parse_args(char *command, char **args)
{
    int argc = 0;
    char *p = command;

    while (*p) {
        while (*p == ' ' || *p == '\t')
            p++;

        if (*p == '\0')
            break;

        if (argc >= MAX_ARGS - 1) {
            fprintf(stderr, "Error: Too many arguments.\n");
            return -1;
        }

        if (*p == '"' || *p == '\'') {
            char quote = *p++;
            args[argc++] = p;

            while (*p && *p != quote)
                p++;

            if (*p != quote) {
                fprintf(stderr,
                        "Error: Unclosed quotation mark.\n");
                return -1;
            }

            *p++ = '\0';
        } else {
            args[argc++] = p;

            while (*p && *p != ' ' && *p != '\t')
                p++;

            if (*p)
                *p++ = '\0';
        }
    }

    args[argc] = NULL;
    return argc;
}

int main(void)
{
    char input[MAX_INPUT];
    char *commands[MAX_COMMANDS];
    char *args[MAX_COMMANDS][MAX_ARGS];

    pid_t pids[MAX_COMMANDS];
    int statuses[MAX_COMMANDS];
    int pipes[MAX_COMMANDS - 1][2];

    int count = 0;
    int created = 0;
    int failed = 0;

    printf("\n========================================\n");
    printf("   MULTI-PROCESS COMMAND PIPELINE\n");
    printf("========================================\n");
    printf("Enter pipeline: ");
    fflush(stdout);

    if (fgets(input, sizeof(input), stdin) == NULL)
        return 0;

    if (strchr(input, '\n') == NULL && !feof(stdin)) {
        fprintf(stderr, "Error: Input too long.\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        return 1;
    }

    input[strcspn(input, "\n")] = '\0';
    trim(input);

    if (!input[0] || input[0] == '|') {
        fprintf(stderr, "Error: Empty input or pipeline stage.\n");
        return 1;
    }

    /* Split the pipeline into command stages. */
    char *saveptr = NULL;
    char *stage = strtok_r(input, "|", &saveptr);

    while (stage != NULL) {
        if (count >= MAX_COMMANDS) {
            fprintf(stderr, "Error: Too many commands.\n");
            return 1;
        }

        trim(stage);

        if (!stage[0]) {
            fprintf(stderr, "Error: Empty pipeline stage.\n");
            return 1;
        }

        commands[count++] = stage;
        stage = strtok_r(NULL, "|", &saveptr);
    }

    /* Parse arguments for each command. */
    for (int i = 0; i < count; i++) {
        int argc = parse_args(commands[i], args[i]);

        if (argc <= 0) {
            fprintf(stderr, "Error parsing command %d.\n", i + 1);
            return 1;
        }
    }

    /* Create all pipes before forking. */
    for (int i = 0; i < count - 1; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");

            for (int j = 0; j < i; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            return 1;
        }
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    /* Create a child process for every command. */
    for (int i = 0; i < count; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            failed = 1;
            break;
        }

        if (pid == 0) {
            if (i > 0 &&
                dup2(pipes[i - 1][0], STDIN_FILENO) == -1) {
                perror("dup2 stdin");
                _exit(126);
            }

            if (i < count - 1 &&
                dup2(pipes[i][1], STDOUT_FILENO) == -1) {
                perror("dup2 stdout");
                _exit(126);
            }

            for (int j = 0; j < count - 1; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            execvp(args[i][0], args[i]);

            perror(args[i][0]);
            _exit(errno == ENOENT ? 127 : 126);
        }

        pids[i] = pid;
        created++;
    }

    /* Close the parent's copies of all pipe descriptors. */
    for (int i = 0; i < count - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    /* Clean up if process creation failed. */
    if (failed) {
        for (int i = 0; i < created; i++)
            kill(pids[i], SIGTERM);
    }

    /* Collect child-process exit statuses. */
    for (int i = 0; i < created; i++) {
        pid_t result;

        do {
            result = waitpid(pids[i], &statuses[i], 0);
        } while (result == -1 && errno == EINTR);

        if (result == -1) {
            perror("waitpid");
            statuses[i] = -1;
            failed = 1;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("\n========== EXECUTION REPORT ==========\n");
    printf("Commands: %d\n", count);
    printf("Processes created: %d\n", created);

    int success = !failed && created == count;

    for (int i = 0; i < created; i++) {
        printf("\nPID: %ld\n", (long)pids[i]);
        printf("Command: %s\n", args[i][0]);

        if (statuses[i] == -1) {
            printf("Status: WAIT ERROR\n");
            success = 0;
        } else if (WIFEXITED(statuses[i])) {
            int code = WEXITSTATUS(statuses[i]);

            printf("Exit code: %d\n", code);

            if (code != 0)
                success = 0;
        } else if (WIFSIGNALED(statuses[i])) {
            printf("Terminated by signal: %d\n",
                   WTERMSIG(statuses[i]));
            success = 0;
        }
    }

    printf("\nElapsed time: %.3f ms\n",
           elapsed_ms(start, end));

    printf("Pipeline status: %s\n",
           success ? "SUCCESS" : "FAILURE");

    printf("======================================\n");

    return success ? 0 : 1;
}
