## Introduction - OS Architecture, Kernel, System Calls

#### Discussion Points & Concept Checking
* what is OS?
* Types of OS in market? 
* Classification - Desktop/Server, embedded/mobile
* Do applications can talk to hardware directly? What are the challenges?
* Services of OS (ofcourse Kernel services)
* Dual mode operations of a CPU, switching to supervisor mode
* OS Components - kernel, drivers, libraries, utilities
* User mode & kernel mode operations
* Memory partitioning - user space, kernel space
* Types of kernel - Monolithic, Micro, Modular
* Linux Modular Kernel concept
* Interrupts
* System calls
* Simple examples - file read & write
* System calls vs Library API, cons and pros
* Tracing system calls - strace

> [Clik Here](Notes.md) for the notes

#### Commands
* Check kernel version
  `uname -r`
* Where is kernel image
  `ls /boot/*`

#### Examples

* Simple examples to understand systems callss
  * Wrting to a file [code](code/wrsample.c)
  * Reading from a file [code](code/rdsample.c)
* `strace` usage
