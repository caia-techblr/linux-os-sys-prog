## Scheduling

## Discussion & Concept Checking
* What is Scheduling
* Ready queue / run queue
* Which processes will be in ready state?
* Scheduling criteria
* CPU Bound vs I/O Bound processes
* Preemptive vs Non preemptive scheduling
* Classical Algorithms 
* Combination of algorithms, e.g. FIFO + RR, FIFO + RR
* Multi level scheduling, Multi level feedback queue scheduling
* Real time constraints
* Practical scheduling in Linux
  * Realtime policies - SCHED_FIFO, SCHED_RR
  * Nonreltime policies - SCHED_OTHER
* Nice values to control priorities in TS poolicy
* Scheduling in SMP


> [Clik Here](Notes.md) for the additional notes

## Commands
```
ps -e -o pid,ppid,stat,policy,pri,ni,cmd
nice -n 5 ./a.out
nice -n -6 ./a.out
```

## System Calls / APIs

## Examples
