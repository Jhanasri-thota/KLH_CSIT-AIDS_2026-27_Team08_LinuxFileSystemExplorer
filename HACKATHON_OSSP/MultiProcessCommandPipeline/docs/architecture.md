# System Architecture

## Overview

The system accepts a pipeline of commands, separates the commands into stages, creates the required pipes and child processes, connects their standard input and output streams, executes each command, and collects process statuses.

## Execution Flow

1. **Input:** The user enters a pipeline.
2. **Parsing:** The program identifies individual commands and their arguments.
3. **Pipe creation:** Communication channels are created between adjacent commands.
4. **Process creation:** Child processes are created using `fork()`.
5. **Stream redirection:** `dup2()` connects the appropriate pipe ends to standard input and output.
6. **Command execution:** Each child executes its command using `execvp()`.
7. **Synchronization:** The parent waits for child processes using `waitpid()`.
8. **Reporting:** The application displays process information, exit statuses, and execution time.

## Architecture Diagram

```text
+---------------------------+
|       User Input          |
+-------------+-------------+
              |
              v
+---------------------------+
|      Command Parser       |
+-------------+-------------+
              |
              v
+---------------------------+
|       Create Pipes        |
+-------------+-------------+
              |
              v
+---------------------------+
|    Create Child Processes |
|          fork()           |
+-------------+-------------+
              |
              v
+---------------------------+
| Connect stdin/stdout      |
|          dup2()           |
+-------------+-------------+
              |
              v
+---------------------------+
| Execute Commands          |
|          execvp()         |
+-------------+-------------+
              |
              v
+---------------------------+
| Collect Process Status    |
|         waitpid()         |
+-------------+-------------+
              |
              v
+---------------------------+
| Display Results and Time  |
+---------------------------+
```

## Core Operating-System Concepts

* Process creation and management
* Inter-process communication
* File descriptors
* Standard input and output redirection
* Process synchronization
* Exit-status handling

## Error Handling

The implementation should detect invalid commands and report unsuccessful execution. Testing should also cover malformed input and failures during process or pipe creation where practical.
