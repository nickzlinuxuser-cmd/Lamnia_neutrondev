# Lamnia_neutrondev
It is a personal project to a new OS
Lamnya OS

Lamnya is an experimental operating system built from scratch with a focus on simplicity, integration, and system clarity.

The goal of Lamnya is to create a small but powerful system where the architecture remains understandable while still being capable of running real applications.

This project is developed independently and documents every step of the system's evolution.

---

Project Philosophy

Lamnya follows a simple principle:

«Simplicity first. Complexity only when necessary.»

The system tries to balance low-level system design with usability, avoiding unnecessary layers or frameworks.

Key ideas behind Lamnya:

- Minimal and understandable kernel architecture
- Tight integration between system components
- A custom user language (".ula")
- Dynamic system modules (".deo")
- A secure interpreter shell ("syssh")

---

Development Stages

Lamnya development follows a structured evolution inspired by atomic elements.

Pre-Release Builds

Version| Stage| Description
Lamnya Proton| Alpha| Early kernel development and debugging environment
Lamnya Neutron| Beta| System stabilization and core feature testing
Lamnya Electron| Transition| Debug shell evolves into the system interpreter

Official Releases

Version| Description
Lamnya Hydrogen| First public version
Lamnya Carbon| First advanced ecosystem stage
Lamnya Oxygen| Expanded system capabilities

---

Boot Pipeline

The system boot sequence is intentionally simple and transparent.

BIOS / Bootloader
↓
Kernel Initialization
↓
Memory Management
↓
Scheduler
↓
Paging
↓
Long Mode (64-bit)
↓
Syscall Interface
↓
Debug Shell / Syssh

Early builds include a debug shell with full privileges to allow low-level system testing.

---

System Components (Planned)

- Kernel
- Memory Manager (Buddy Allocator)
- Scheduler
- Paging System
- System Calls Interface
- Syssh Interpreter
- Native Applications

---

License

This project is licensed under the GPL-3.0 License.

This means:

- The code is free to study and modify
- Contributions are welcome
- All derivative work must remain open source

See the "LICENSE" file for details.

---

Development Log

Development progress and system milestones are documented publicly.

Community discussions and updates may appear on platforms such as:

- GitHub
- Reddit (development logs)

---

Authors

Nicolas Ramos
Founder of the Lamnya project

Wender
Core collaborator

---

Status

Lamnya is currently in early development.

Expect rapid changes as the architecture evolves.
