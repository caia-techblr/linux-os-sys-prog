## Process Management

#### Discussion & Concept Checking
* What is Process
* Program vs Process
* Sections of a program on disk (header, code& idata), process in memory (code, idata, udata, stack, heap etc)
* Kernel support for a process - pid, process descriptor, entry in process table
* process descriptor/control block, process attributes
* process states - ready, running, blocked, terminated
* process life cycle, with state transitions
* what are blocking , non blocking calls?
* context switching - context saving + context loading
* When context switching occurs, who takes care of switching
* Process hierarchy, origin process, parent-child relationship
* Process creation
* Process termination

> [Clik Here](Notes.md) for the additional notes

#### Commands
* process listing with ps
  ```
  ps
  ps -el
  ps aux
  ps -e -o pid,ppid,stat,cmd
  ```
* pstree
  ```
  pstree
  pstree -np
  ```
* Top
  `top # how to quit top view`

#### Examples
* Simple fork usage [code](code/example0.c)
* fork example [code](code/example1.c), [notes](Notes.md#fork)
* concurrency [code1](code/example2a.c), [code2](code/example2a.c)
* Adoption/Reparenting to init [code](code/example3.c)
* waitpid usage [code](code/example4.c), [notes](Notes.md#waitpid)
* zombie process [code](code/example5.c) [notes](Notes.md#zombie)
* execl demo [code](code/example6.c) [notes](Notes.md#execl)

