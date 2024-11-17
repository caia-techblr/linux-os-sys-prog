# Notes

## Process attributes
* pid, ppid, cmd
* sched policy, priority
* memory description
* file description
* i/o description
* ownership & group
* exit status

## Process States
* Ready
* Running
* Blocked
* Terminated

## Process Transitions
* Ready to Running
* Running to Blocked
* Blocked to Ready
* Running to Terminated
* Running to Ready

## Context Switching
* Context Saving, Contex Loading
* Context Save Area
* Who takes care of context switching (who invokes scheduler?)
  * blocked
  * preempted
  * terminated

## Process Hierarchy
* origin process
* parent-child relationship

## fork
* Creates a new process known as child process
* New pid, PCB/PD will be allocated to child (new entry in process table)
* Duplicates resources from parent to child
* fork returns zero to child, non zero to parent
* Child resumes from next statement after fork
* Parent & child run concurrently 

## exit - process termination
* normal termination - success / failure
* abnormal termination 
* difference between exit lib call, _exit system call

## waitpid
* Blocks parent process till completion of child process
* Collect exit status of child
* Cleans some pending resources of child (else child will become Zombie)
* waitpid paramaters
  * 1st param : pid of child process waiting for, -1 means any one child
  * 2nd param : status of terminated child (pass by address)
  * 3rd param : flags
* Macros WEXITSTATUS, WIFEXITED to check exit status, normal/abnormal termination

## zombie process
* A process got terminated, but not cleaned up by parent (no waitpid call) is known as zombie process (in zombie state)
* Typically exit will release all resources, except PCB/PD and entry in process table
* waitpid by parent is expected to clear these
* Too many zombie process causes process table to be full and failure of future fork request
* It's adviced that parent should use waitpid, even blocking & exit status collection not required

## execl
* Overwrites child address space with resources of specified program
* Process remains same, but program/resources will change
* Any code after execl is redundant, if execl succeeds
* execl vs execlp vs execv

## Mini shell design
* Display some string as shell prompt
* Take command name (string) as input from user
* Create a child process
* Launch new program/command in child using execl'
* Parent will wait for completion of child
* Repeat until given input is "quit"
