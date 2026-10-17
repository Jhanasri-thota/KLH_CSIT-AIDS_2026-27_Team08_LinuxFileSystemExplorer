# Multi-Process Command Pipeline System

## 1. Project Overview

The Multi-Process Command Pipeline System is a C-based Linux application that executes multiple commands connected through pipes. It demonstrates operating-system concepts such as process creation, inter-process communication, input/output redirection, process synchronization, and exit-status collection.

## 2. Problem Statement

Executing a series of Linux commands manually can be inconvenient when the output of one command must become the input of another. This project implements a custom command-pipeline executor that automates this process using Linux system calls and process-management functions.

## 3. Objectives

* Execute multiple commands connected by pipes.
* Create child processes using `fork()`.
* Establish inter-process communication using `pipe()`.
* Redirect standard input and output using `dup2()`.
* Execute commands using `execvp()`.
* Collect process statuses using `waitpid()`.
* Report process information and execution time.

## 4. Technologies Used

* Programming language: C
* Operating system: Linux / Ubuntu WSL
* Compiler: GCC
* Build system: GNU Make
* Version control: Git and GitHub
* System interfaces: POSIX process and pipe APIs

## 5. Project Structure

```text
MultiProcessCommandPipeline/
├── src/
│   └── main.c
├── tests/
│   └── test_pipeline.sh
├── docs/
├── data/
│   └── sample.log
├── results/
├── reports/
├── screenshots/
├── Makefile
├── README.md
└── .gitignore
```

## 6. Prerequisites

Install GCC, GNU Make, and Git on Ubuntu:

```bash
sudo apt update
sudo apt install build-essential git
```

## 7. Compilation

Navigate to the project directory:

```bash
cd MultiProcessCommandPipeline
```

Compile the application:

```bash
make clean
make
```

## 8. Execution

Start the application:

```bash
./pipeline
```

Enter a pipeline such as:

```bash
cat data/sample.log | grep ERROR | sort | uniq -c
```

The application executes the commands and reports the resulting output and process information.

## 9. Testing

Run the automated test suite:

```bash
chmod +x tests/test_pipeline.sh
./tests/test_pipeline.sh
```

Record the actual test results in `results/test_results.md`.

## 10. Operating-System Concepts

| Function    | Purpose                                                       |
| ----------- | ------------------------------------------------------------- |
| `fork()`    | Creates a child process.                                      |
| `pipe()`    | Creates a communication channel.                              |
| `dup2()`    | Redirects standard input or output.                           |
| `execvp()`  | Replaces a child process with the requested program.          |
| `waitpid()` | Waits for child-process termination and retrieves its status. |

## 11. Limitations

This application implements a custom pipeline executor, not a complete Linux shell. Supported syntax is limited to the functionality implemented in the parser. Features such as shell variable expansion, command substitution, output redirection, and complex quoting may not be supported.

## 12. Responsible Implementation

Run the application in a controlled environment with commands that are safe and appropriate for testing. Avoid destructive commands and commands that interfere with other users or system services.

## 13. Future Enhancements

* Support additional command-line syntax.
* Improve parser error messages.
* Add more comprehensive automated tests.
* Provide pipeline execution statistics.
* Add configurable logging and execution limits.

## 14. Conclusion

The project demonstrates how Linux processes communicate and coordinate through pipes, process creation, input/output redirection, and process synchronization.
