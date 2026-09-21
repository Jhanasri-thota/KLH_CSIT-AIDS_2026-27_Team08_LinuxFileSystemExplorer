# KLH_CSIT-AIDS_2026-27_Team08_LinuxFileSystemExplorer
# Linux File System Explorer Using System Calls

A Linux-based command-line application for exploring and managing files and directories using Linux system calls and POSIX APIs.

---

## 1. Project Information

| Detail | Information |
|--------|-------------|
| **Project Title** | Linux File System Explorer Using System Calls |
| **Course** | Operating Systems and Systems Programming |
| **Course Code** | 25CS2104E |
| **Academic Year** | 2026–27 |
| **Term** | Term-I |
| **Section No.** | 12 |
| **Team No.** | 08 |
| **Programming Language** | C / C++ |
| **Operating Environment** | Linux / Ubuntu |
| **Compiler** | GCC |
| **Version Control** | Git / GitHub |

---

# 2. Team Members

| S.No. | Roll Number | Student Name | Individual Responsibility |
|------:|-------------|--------------|---------------------------|
| 1 | 2520080045 | Sindhuja | Project design, menu-driven interface, file creation, reading, writing, and overall integration |
| 2 | 2520090121 | Jhanasri Thota | Directory operations using `mkdir()`, `opendir()`, `readdir()`, and `closedir()` |
| 3 | 2520090126 | Alekhya | File information and deletion using `stat()` and `unlink()`, error handling, testing, documentation, and GitHub management |

The individual responsibilities are based on the project problem statement submission document. :contentReference[oaicite:2]{index=2}

---

# 3. Supervisor

**Faculty Name:** Raghupathi Manthena

---

# 4. Abstract

The Linux File System Explorer Using System Calls is a Linux-based command-line application designed to explore and manage files and directories using Linux system calls and POSIX APIs. The project focuses on understanding how a user-space program interacts with the Linux operating system and its file system.

The proposed system will allow users to perform basic file-system operations such as listing directory contents, creating files and directories, reading and writing files, viewing file information, and deleting files. Linux APIs and system calls such as `open()`, `read()`, `write()`, `close()`, `mkdir()`, `opendir()`, `readdir()`, `stat()`, and `unlink()` will be used to implement these operations.

The project demonstrates important Operating Systems and System Programming concepts, particularly system calls, file descriptors, file abstraction, directory management, file I/O, and interaction between user space and kernel services. It primarily addresses **CO-5: File Systems, File Abstractions, and File I/O in Linux**, with a connection to **CO-1: The OS as a Service Layer**.

The expected outcome is a simple and functional terminal-based file explorer that provides practical understanding of Linux file-system operations and system programming.

---

# 5. Problem Statement

Linux provides various commands and utilities for managing files and directories, but using these commands alone does not give a clear understanding of how the operating system performs file operations internally.

Students need practical exposure to how user programs interact with the Linux kernel through system calls.

Therefore, this project aims to develop a Linux-based command-line file system explorer that performs basic file and directory operations using Linux system calls and POSIX APIs.

The system will support operations such as:

- Listing directory contents
- Creating files
- Creating directories
- Reading files
- Writing files
- Viewing file information
- Deleting files

These operations demonstrate how applications communicate with the Linux operating system and how the operating system provides file-system services through system calls and POSIX APIs.

---

# 6. Motivation

The Linux operating system provides several commands and utilities for file and directory management. Although these commands are useful for everyday tasks, simply using them does not provide a clear understanding of what happens internally when a file operation is performed.

This project provides practical exposure to low-level file-system operations by implementing them through Linux system calls and POSIX APIs.

The project helps in understanding:

- How user-space applications communicate with the Linux kernel
- How files are opened and accessed
- How file descriptors are used
- How data is read from and written to files
- How directories are accessed and traversed
- How file metadata is obtained
- How files are removed from the file system
- How system calls provide services to user applications

---

# 7. Objectives

The major objectives of the project are:

1. To develop a Linux-based command-line file system explorer for performing basic file and directory operations.

2. To implement file and directory operations using Linux system calls and POSIX APIs.

3. To understand and demonstrate Operating Systems concepts such as:
   - System calls
   - File descriptors
   - File abstraction
   - Directory management
   - File I/O

4. To provide practical experience in Linux System Programming.

5. To understand how a user-space application interacts with the Linux kernel.

6. To demonstrate the role of the Operating System as a service layer.

---

# 8. Key Features

The Linux File System Explorer provides a menu-driven interface for performing common file-system operations.

### Main Features

- List directory contents
- Create a new file
- Write data into a file
- Read data from a file
- Create a new directory
- View file information
- Delete a file
- Handle invalid operations
- Display appropriate error messages
- Interact with the Linux file system through system calls and POSIX APIs

---

# 9. Functionalities

## 9.1 List Directory Contents

The application allows the user to view the contents of a directory.

The directory is opened using:

```c
opendir()
