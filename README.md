# 🐧 Linux File System Explorer Using System Calls

A menu-driven Linux application developed using C to demonstrate operating system concepts, Linux system calls, file and directory management, process management, inter-process communication (IPC), memory management, and thread synchronization.

---

## 📚 Course Information

| Detail | Information |
|---|---|
| Course Name | Operating System and System Programming |
| Course Code | 25CS2104E |
| Project Title | Linux File System Explorer System Calls |
| Team Number | 08 |
| Department | Computer Science and Engineering |
| Faculty Guide | Raghupathi M |

---

## 👥 Team Members

| S. No. | Team Member | Roll Number |
|---:|---|---|
| 1 | Sindhuja | 2520080045 |
| 2 | Jhanasri | 2520090121 |
| 3 | Alekhya | 2520090126 |

---

## 📖 Project Overview

The **Linux File System Explorer** is a menu-driven command-line application developed in C to demonstrate Linux operating system and systems programming concepts.

The application provides an interactive interface for managing files and directories. It also includes separate modules for process management, inter-process communication, memory management, and thread synchronization.

The project demonstrates how user-space applications interact with Linux operating system services through system calls and system programming interfaces.

It provides practical exposure to Linux filesystem operations, file I/O, process-related concepts, IPC mechanisms, memory management, and concurrency.

---

## 🎯 Project Objectives

- Understand the role of the operating system in providing services to applications.
- Learn how user-space programs interact with the Linux kernel.
- Perform file and directory operations using Linux interfaces.
- Understand file metadata and file positioning.
- Explore process management and process control.
- Demonstrate inter-process communication using pipes, FIFOs, and signals.
- Explore memory management concepts.
- Understand thread synchronization and concurrency.
- Apply C programming and Linux systems programming concepts in a practical project.

---

## ✨ Project Features

### 1. File and Directory Management

The application provides the following features:

- List directory contents.
- Create files.
- Write data to files.
- Read file contents.
- Create directories.
- Remove directories.
- View file information.
- Delete files.
- Display the current working directory.
- Change directories.
- Manage file positions using `lseek()`.

### 2. Process Management

A dedicated menu option provides access to the Process Management module.

This module is intended to demonstrate process-related operating system concepts supported by the implementation.

### 3. Inter-Process Communication (IPC)

The project contains modules for:

- Anonymous pipe communication.
- Named pipe (FIFO) communication.
- Signal-related communication.

### 4. Memory Management

The application includes a dedicated Memory Management module for exploring memory-related operating system concepts.

### 5. Thread Synchronization

A dedicated Thread Synchronization menu option provides access to the project's thread-related functionality.

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C Programming | Application development |
| Linux | Operating system environment |
| Linux system calls and APIs | File and directory operations |
| GCC | C compiler |
| GNU Make | Build automation |
| POSIX IPC interfaces | Pipe, FIFO, and signal-related operations |
| POSIX Threads | Thread functionality, where implemented |
| Git | Version control |
| GitHub | Source code hosting |

---

## 📂 Project Structure

```text
KLH_CSIT-AIDS_2026-27_Team08_LinuxFileSystemExplorer/
│
├── .gitignore
│
├── PROJECT_LinuxFileExplorer/
│   └── README.md
│
├── data/
│   └── .gitkeep
│
├── docs/
│   ├── OSSP Abstract Batch-8.pdf
│   ├── OSSP_Project PPT.pptx
│   └── ossp.txt
│
├── reports/
│   └── .gitkeep
│
├── results/
│   └── .gitkeep
│
└── src/
    ├── Makefile
    ├── main.c
    ├── file_explorer
    ├── ossp.txt
    ├── sin
    │
    ├── filesystem/
    │   ├── directory_operations.c
    │   ├── file_info.c
    │   └── file_operations.c
    │
    ├── include/
    │   ├── directory_operations.h
    │   ├── fifo_operations.h
    │   ├── file_info.h
    │   ├── file_operations.h
    │   ├── memory_operations.h
    │   ├── pipe_operations.h
    │   ├── process_operations.h
    │   ├── signal_operations.h
    │   └── thread_operations.h
    │
    ├── ipc/
    │   ├── fifo_operations.c
    │   ├── fifo_receiver.c
    │   ├── fifo_sender.c
    │   ├── pipe_operations.c
    │   └── signal_operations.c
    │
    └── memory/
        └── memory_operations.c
```

*Note: This tree summarizes the main project files recorded during development. Additional files may exist in the repository.*

---

# 📘 Course Outcome (CO)-Wise Topic Mapping

The following tables map the project modules and menu features to the six Course Outcomes in the Operating System and System Programming syllabus.

**Important:** The mapping distinguishes the modules present in the project from individual syllabus topics whose implementation must be verified in the source code.

## 🔹 CO-1: The OS as a Service Layer

**Project Area:** Linux File and Directory Operations

| S. No. | Syllabus Topic | Project Feature / Application |
|---:|---|---|
| 1 | Operating System as a Layered Service Abstraction | The application requests operating system services to perform file and directory operations. |
| 2 | User Space and Kernel Space | The project runs as a user-space application and uses Linux interfaces to access OS services. |
| 3 | System Calls and Kernel Services | File and directory operations use Linux system interfaces, depending on the implementation. |
| 4 | Role of the Shell as a User-Space Program | The Linux shell is used to launch the compiled application. |
| 5 | Command Execution Journey | The shell starts the executable, which performs the requested operations. |
| 6 | Linux Architecture and System Software Stack | The application demonstrates interaction with Linux filesystem services. |
| 7 | Systems Programming Fundamentals | The project uses C and Linux programming interfaces. |

**Related Features:** File creation, reading, writing, directory management, and file positioning.

**Learning Outcome:** Understand how a user-space application interacts with operating system services.

---

## 🔹 CO-2: Processes and Process Control

**Project Module:** Process Management — Menu Option 12

| S. No. | Syllabus Topic | Project Feature / Application |
|---:|---|---|
| 1 | Process Abstraction | Understanding the File System Explorer as a running Linux process. |
| 2 | Process Lifecycle and State Transitions | Understanding process execution and termination. |
| 3 | Creation, Execution, Synchronization and Termination | Related to process-control functionality provided by the implementation. |
| 4 | User-Level Process Scheduling Concepts | Related theoretical concept; a custom scheduler is not established by the menu alone. |
| 5 | Common Process Management Pitfalls | Relevant to process error handling and resource management. |

**Related Project Area:** `Process Management`

**Learning Outcome:** Understand process-related operating system concepts and the role of process control.

*Implementation note: Specific operations such as `fork()`, `exec()`, `wait()`, or `exit()` should be claimed as implemented only if they appear in the source code.*

---

## 🔹 CO-3: Inter-Process Communication (IPC)

**Project Modules:**
- Menu Option 13: IPC — Pipe Communication
- Menu Option 14: IPC — FIFO Communication
- Menu Option 15: IPC — Signal Communication

| S. No. | Syllabus Topic | Related Project Feature | Source File |
|---:|---|---|---|
| 1 | Inter-Process Communication | IPC modules | `src/ipc/` |
| 2 | Anonymous Pipes | Pipe communication | `src/ipc/pipe_operations.c` |
| 3 | Named Pipes (FIFOs) | FIFO communication | `src/ipc/fifo_operations.c` |
| 4 | Signals and Asynchronous Notifications | Signal-related operations | `src/ipc/signal_operations.c` |
| 5 | Signal Handlers and POSIX Signal Programming | Related to the signal module; verify the implemented handlers in source code. | `src/ipc/signal_operations.c` |
| 6 | Process Groups, Sessions, and Job Control | Related syllabus concepts; implementation is not established by the current project menu. | Requires verification |

**Related Source Files:**

- `src/ipc/pipe_operations.c`
- `src/ipc/fifo_operations.c`
- `src/ipc/fifo_sender.c`
- `src/ipc/fifo_receiver.c`
- `src/ipc/signal_operations.c`

**Learning Outcome:** Understand how Linux provides different mechanisms for communication and notification between processes.

---

## 🔹 CO-4: Memory Management

**Project Module:** Memory Management — Menu Option 16

| S. No. | Syllabus Topic | Project Feature / Application |
|---:|---|---|
| 1 | Virtual Memory as an Operating System Abstraction | Related memory-management concept. |
| 2 | Address Translation and Page Tables | Linux memory-management concept; direct implementation is not established. |
| 3 | Page Faults and Demand Paging | Operating system memory-management concepts. |
| 4 | Linux Process Address Space Layout | Related to the memory layout of a running process. |
| 5 | Dynamic Memory Allocation in Linux | Relevant if the implementation includes dynamic memory allocation. |
| 6 | Copy-on-Write and Process Creation | Related concept if process creation and memory behavior are demonstrated. |
| 7 | Memory Errors and Operating System Responses | Relevant to memory error handling, where implemented. |
| 8 | Memory Debugging and Analysis Tools | Can be explored using external debugging tools if included in project testing. |

**Related Source File:** `src/memory/memory_operations.c`

**Learning Outcome:** Explore memory-management concepts and understand how Linux processes use memory.

*Implementation note: The presence of a Memory Management menu option does not by itself prove that page tables, page faults, demand paging, or copy-on-write are directly implemented by the project.*

---

## 🔹 CO-5: File Systems, File Abstractions, and File I/O in Linux

**Project Module:** Linux File System Explorer — Menu Options 1–11

**Primary Course Outcome of the Project**

| Menu Option | Project Feature | Related Syllabus Topic |
|---:|---|---|
| 1 | List Directory | Directory entries and file naming |
| 2 | Create File | File abstraction and file creation |
| 3 | Write File | File output and file I/O |
| 4 | Read File | File input and file I/O |
| 5 | Create Directory | Directory management |
| 6 | Remove Directory | Directory removal |
| 7 | View File Information | File metadata and information |
| 8 | Delete File | File deletion |
| 9 | Show Current Directory | Current working directory |
| 10 | Change Directory | Directory navigation |
| 11 | File Position using `lseek()` | File offsets and file positioning |

### CO-5 Syllabus Mapping

| S. No. | Syllabus Topic | Project Application |
|---:|---|---|
| 1 | File Abstractions | Files are created, read, written, and deleted. |
| 2 | The Unix File Abstraction | File operations use Linux filesystem interfaces. |
| 3 | Inodes, Directory Entries, and File Naming | Directory listing and file information relate to filesystem organization. |
| 4 | Virtual File System (VFS) | File operations use Linux filesystem interfaces. |
| 5 | File Descriptors and Open File Management | Relevant to operations using file descriptors. |
| 6 | Linux File I/O System Calls | File creation, reading, writing, and positioning. |
| 7 | Buffered and Unbuffered I/O | Depends on whether standard I/O functions or system-call interfaces are used. |
| 8 | Memory-Mapped File I/O | Not established by the current menu; requires `mmap()`-related implementation. |
| 9 | ext4 File System Overview | Related Linux filesystem background; direct ext4 manipulation is not established. |

### Related Source Files

- `src/filesystem/file_operations.c`
- `src/filesystem/directory_operations.c`
- `src/filesystem/file_info.c`
- `src/include/file_operations.h`
- `src/include/directory_operations.h`
- `src/include/file_info.h`

**Learning Outcome:** Understand Linux file abstractions, file I/O, directory operations, file metadata, and file positioning.

---

## 🔹 CO-6: Concurrency and Synchronization

**Project Module:** Thread Synchronization — Menu Option 17

| S. No. | Syllabus Topic | Project Feature / Application |
|---:|---|---|
| 1 | Threads and Processes | Understanding the differences between processes and threads. |
| 2 | POSIX Threads | Related to thread functionality if POSIX thread APIs are used. |
| 3 | Race Conditions and Shared Data | Relevant when multiple threads access shared resources. |
| 4 | Mutual Exclusion Using Mutexes | Applicable if mutex operations are implemented. |
| 5 | Condition Variables and Thread Coordination | Applicable if condition variables are implemented. |
| 6 | Counting Semaphores | Applicable if semaphore operations are implemented. |
| 7 | Deadlocks and Concurrency Hazards | Related concurrency concepts. |
| 8 | Advanced Synchronization Concepts | Depends on the synchronization mechanisms actually implemented. |

**Related Project Area:** Thread Synchronization.

**Related Header File:** `src/include/thread_operations.h`

**Learning Outcome:** Understand thread-related concepts and synchronization in Linux.

*Implementation note: The exact thread implementation source file and the use of mutexes, condition variables, or semaphores should be verified before claiming those features.*

---

## 📊 Overall CO Coverage Summary

| Course Outcome | Project Module | Main Concepts | Project Relevance |
|---|---|---|---|
| CO-1 | Linux File and Directory Operations | OS services, user space, system calls | Foundational |
| CO-2 | Process Management | Process abstraction and process control | Additional module |
| CO-3 | IPC | Pipes, FIFOs, and signals | Additional module |
| CO-4 | Memory Management | Memory-management concepts | Additional module |
| CO-5 | File System Explorer | File I/O, directory operations, metadata, `lseek()` | **Primary focus** |
| CO-6 | Thread Synchronization | Threads and concurrency | Additional module |

---

## ⚙️ System Requirements

Before compiling the project, ensure that the following are available:

- Linux operating system or compatible Linux environment.
- GCC compiler.
- GNU Make.
- Terminal or shell.

Ubuntu on Windows Subsystem for Linux (WSL) can be used as a Linux development environment.

Check the installed tools:

```bash
gcc --version
make --version
```

---

## 🚀 Installation and Execution

### Step 1: Clone the Repository

```bash
git clone https://github.com/Jhanasri-thota/KLH_CSIT-AIDS_2026-27_Team08_LinuxFileSystemExplorer.git
```

### Step 2: Navigate to the Source Directory

```bash
cd KLH_CSIT-AIDS_2026-27_Team08_LinuxFileSystemExplorer/src
```

### Step 3: Compile the Project

```bash
make
```

The Makefile defines the build process for the application.

### Step 4: Run the Application

After successful compilation, run:

```bash
./file_explorer
```

**Note:** If the executable does not exist or compilation fails, inspect the targets and compiler commands in `src/Makefile` before proceeding.

---

## 🖥️ Application Menu

The application displays an interactive menu similar to the following:

```text
==========================================
       LINUX FILE SYSTEM EXPLORER
==========================================
1.  List Directory
2.  Create File
3.  Write File
4.  Read File
5.  Create Directory
6.  Remove Directory
7.  View File Information
8.  Delete File
9.  Show Current Directory
10. Change Directory
11. File Position using lseek()
12. Process Management
13. IPC - Pipe Communication
14. IPC - FIFO Communication
15. IPC - Signal Communication
16. Memory Management
17. Thread Synchronization
18. Exit
==========================================
```

---

## 🧪 Testing and Validation

The project can be tested by checking the behavior of each implemented menu option.

| Test Area | Example Validation |
|---|---|
| Directory Listing | Verify that directory entries are displayed. |
| File Creation | Create a file and confirm that it exists. |
| File Writing | Write content and check the resulting file. |
| File Reading | Read the content of an existing file. |
| Directory Creation | Create a directory and verify it. |
| Directory Removal | Remove an eligible empty directory. |
| File Information | Display metadata for an existing file. |
| File Deletion | Delete a test file and confirm its removal. |
| Working Directory | Display the current directory. |
| Directory Navigation | Change to a valid directory. |
| File Position | Test file positioning using `lseek()`. |
| IPC | Verify pipe, FIFO, and signal behavior according to the implementation. |
| Process Management | Test the implemented process-related operations. |
| Memory Management | Test the implemented memory-related functionality. |
| Thread Synchronization | Test the implemented thread functionality. |

Run tests only in a designated test directory and avoid deleting important files.

---

## 🔒 Error Handling and Reliability

System programming applications should check the return values of system calls and handle errors appropriately.

Potential error conditions include:

- File not found.
- Permission denied.
- Invalid paths.
- Failed file operations.
- Failed directory operations.
- Memory allocation failures.
- Process creation or termination failures.
- IPC errors.
- Thread synchronization errors.

The actual error-handling behavior depends on the project implementation.

---

## 🎓 Learning Outcomes

This project provides practical exposure to:

- Linux systems programming using C.
- Operating system services and system interfaces.
- File and directory management.
- File metadata and file positioning.
- Process management concepts.
- IPC using pipes, FIFOs, and signals.
- Memory-management concepts.
- Thread synchronization and concurrency.
- Compilation and build automation using GCC and Make.

---

## 🔮 Future Enhancements

Possible improvements include:

- Recursive directory exploration.
- File searching and filtering.
- File permission management.
- Improved metadata display.
- More detailed process monitoring.
- Additional IPC demonstrations.
- Expanded memory-management demonstrations.
- Improved thread synchronization examples.
- Automated testing.
- Memory debugging and performance analysis.

These are potential enhancements and are not necessarily part of the current implementation.

---

## 📄 Project Documentation

The `docs/` directory contains project documentation and presentation materials, including:

- `OSSP Abstract Batch-8.pdf`
- `OSSP_Project PPT.pptx`
- `ossp.txt`

---

## 👨‍🏫 Faculty Guide

**Raghupathi M**  
CSE Department

---

## 📜 Academic Purpose

This project was developed as part of the **Operating System and System Programming (25CS2104E)** course to explore Linux operating system concepts through practical systems programming.

---

## 🙏 Acknowledgment

We express our sincere gratitude to our faculty guide, **Raghupathi M**, for guidance and support throughout the project.

We also thank the Department of Computer Science and Engineering for providing the opportunity to learn and apply Linux systems programming concepts through this project.

---

## 🔗 GitHub Repository

[Linux File System Explorer Using System Calls](https://github.com/Jhanasri-thota/KLH_CSIT-AIDS_2026-27_Team08_LinuxFileSystemExplorer)
