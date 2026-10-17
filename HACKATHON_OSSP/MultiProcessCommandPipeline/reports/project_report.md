# Project Report

## Multi-Process Command Pipeline System

### 1. Abstract

The Multi-Process Command Pipeline System is a Linux-based application developed in C to demonstrate command execution through multiple processes. It connects commands using pipes and employs process-management functions to execute and synchronize them. The project illustrates fundamental operating-system concepts, including process creation, inter-process communication, file-descriptor manipulation, and process-status collection.

### 2. Introduction

Modern operating systems provide mechanisms for executing independent programs and connecting their input and output streams. This project implements a custom command-pipeline executor that combines multiple commands into a single processing workflow.

### 3. Problem Statement

Users often need to execute several commands in sequence, passing the output of one command to another. The project aims to automate this workflow while demonstrating the operating-system mechanisms behind pipeline execution.

### 4. Objectives

* Execute multiple commands through a pipeline.
* Demonstrate process creation using `fork()`.
* Establish communication using `pipe()`.
* Redirect file descriptors using `dup2()`.
* Execute programs using `execvp()`.
* Synchronize child processes using `waitpid()`.
* Report process statuses and execution time.

### 5. Proposed System

The application accepts a pipeline, parses its commands, creates pipes and child processes, connects the command streams, executes the programs, and collects their termination statuses.

### 6. System Requirements

**Software**

* Ubuntu Linux or Ubuntu WSL
* GCC compiler
* GNU Make
* Git

**Programming language**

* C

**Operating-system interfaces**

* `fork()`
* `pipe()`
* `dup2()`
* `execvp()`
* `waitpid()`

### 7. Implementation

The command parser identifies pipeline stages and their arguments. The process-management component creates the necessary child processes. Pipe file descriptors connect the output of one stage to the input of the next. The parent process waits for the children and reports execution information.

### 8. Testing Methodology

The application is tested with basic command execution, sorting, word counting, multi-stage log analysis, and invalid-command handling.

The actual results of each test must be recorded in the test-results document. Failed tests must be investigated rather than reported as successful.

### 9. Results

Insert terminal screenshots showing successful pipeline execution, process reports, and error handling.

Include the actual automated-test summary and any observed limitations. Do not claim performance improvements without measured evidence.

### 10. Limitations

The application supports only the command syntax implemented by its parser. It is not a complete shell and may not support shell variables, redirection, command substitution, or advanced quoting.

### 11. Future Enhancements

Potential enhancements include stronger input validation, additional parser features, broader test coverage, and more detailed execution statistics.

### 12. Conclusion

The project demonstrates fundamental Linux process-management and inter-process communication techniques through a working command-pipeline executor.

### 13. References

* Linux manual pages: `fork(2)`, `pipe(2)`, `dup2(2)`, `exec(3)`, and `waitpid(2)`.
* GNU Compiler Collection documentation.
* GNU Make documentation.

### 14. Team Contributions

| Team Member | Responsibility | Contribution                      |
| ----------- | -------------- | --------------------------------- |
| Member 1    | Implementation | Complete with actual contribution |
| Member 2    | Testing        | Complete with actual contribution |
| Member 3    | Documentation  | Complete with actual contribution |
| Member 4    | Presentation   | Complete with actual contribution |

Replace these example entries with the actual team members and their real contributions.
