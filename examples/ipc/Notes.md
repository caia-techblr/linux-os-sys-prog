# Notes

## IPC Needs 
* Data Exchange
  * sharing data between the processes
  * OS support:- shared memory, message queues, pipes/fifos
* Synchronization
  * Among multiple processes/threads only one should access a shared resource at a time (Mutual Exclusion)
  * A particular section of a process/thread should execute only after completion of particular section of other process/thread
  * OS support:- Semaphores, Mutex, Spinlocks, Condition Variables, Event Flags

## Race conditions
* When a shared resource is accessible by two or more processes/threads, the final state
  of the resource is inconsistent depending order of executing instructions from each process.
* The final results are unpredictable due to concurrent execution (resource access)

## Mutual Exclusion
* Portion of code in a process/thread dealing with shared resources is considered as critical section
* Among multiple processes/threads only one process/thread can enter related critical section at a time, i.e. only one can access shared resource at a time. This is known as Mutual Exclusion 

## How to acheive Mutual Exclusion
* Disable Interrupts??
* H/w supported atomic instructions, for e.g. XCHG in x86, SWP in ARM
* Atomic instructions in SMP?? Hint:- Bus locking techniques
* Peterson's algorithm/solution based on busy waiting/spinning.
* OS or Software level solutions :- Semaphores, Mutex, Spinlocks etc

## Semaphores
* Semaphore is a kernel/lib level data structure with
  * an integer variable
  * wait queue of processes/threads
* lock operation (down/wait/acquire/take/get)
  * if sem.value > 0, --sem.value and go ahead  (A)
  * if sem.value == 0, block current process/thread and add to wait Q (B)
* unlock operation (up/post/release/give/put)
  * if sem.waitQ is non empty remove one process/thread from Q and resume (C), no change in semaphore value
  * if sem.waitQ is empty, ++sem.value (D)
* Semaphores for simple critical section scenario
* Semaphores for sequencing between execution (dependency)
* Potential problems with misuse of semaphores

## Mutex
* Mutex is not just a binary semaphore
* Mutex is applicable strictly for mutual exclusion
* Ownership applicable, i.e. whichever process/thread locks mutex can only unlock
* Unlocking before locking or unlocking more than once not allowed
* We may say that mutex support subset of semaphore operations applicable for mutual exclusion only.

## Producer Consumer Problem
* There is a shared buffer (stack/queue or any data set) which is accessible by multiple processes/threads
* Processes known as producers add data to buffer (insert/push)
* Processes known as consumer remove data from buffer (delete/pop)
* Rules
  * Rule-1: If buffer is empty consumer should be blocked
  * Rule-2: If buffer is full producers should be blocked
  * When both producers/consumers are allowed, either one producer or one consumer only one should access the buffer
* Solution with a) semaphores b) semaphores + mutex

## Deadlocks
* Two are more processes infinitely blocked (forever) due to circular dependency of resources
* Some examples
  * Arbitrary locking of multiple semaphores
  * Parent & child - unlocking semaphore after waitpid
  * Producer consumer problem - order of locking
* Prevention techniques
  * When multiple locking is required, lock all at a time (Atomic locking), i.e. acquire all resources at a time
  * Release the resource, when waiting for others , e.g. condition variables release mutex if dependency is not met

