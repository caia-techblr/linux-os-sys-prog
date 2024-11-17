# Threads

## Discussion & Concept Checking
* What is a thread?
* Key points about threads
  * Resource sharing
  * Concurrent execution
* Examples of multi threadded application
* CPU multiplexing among multiple threads (logical/pseudo parallelism)
* Parallel threads in multicore systems (true/physical parallelism)
* Task Driven vs Data Driven parallelism
* Scope of multithreaded applications
  * I/O centric (frequent blocking), utilization is better even in single CPU
  * CPU centric (less blocking), efficient in SMP only
* Every application/process runs as single thread of control initially
* Private stack for each thread (context & stack per thread)
* Thread models
  * user level (many to one), e.g. UNIX
  * kernel level (one to one), e.g. LINUX
* Thread cancellation 
* Cancellation policies - asynchronous, deferrred
* Detachable Threads
* Thread pool concept
* Symmetric Multithreading(SMT), e.g. Hyperthreading
* CPU Affinity of threads (CPU Pinning)

## Commands
```
ps -e -L -o pid,ppid,lwp,nlwp,cmd
```

## pthread APIs
* pthread_create, clone system call
* pthread_join
* pthread_exit
* pthread_self
* pthread_exit

> [Clik Here](Notes.md) for the additional notes

#### Examples
* simple example [code](code/psample.c)
* concurrency example [code](code/pconcur.c)
* common task body, data driven example [code](code/psingle.c)
* multiple threads using array [code](code/pmulti.c)
