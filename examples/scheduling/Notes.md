# Notes

## Scheduling criteria
* CPU Utilization - max utilization of CPU, CPU shouldn't idle unnecessarily
* Throughput - no.of processes/threads executed per unit time
* Turnaround time - time elapsed between process creation to termination, time spent in ready, running, blocked states
* Scheduling latency/delay/jittter - time spent in ready state (difference between scheduled time , arrival time into ready queue)
* Response time - time taken for first i/o (interactiveness, user satisfaction)
* Fairness among processes/threads
* No Starvation

## Some classification
* Preemptive vs Non Preemptive scheduling
* I/O Bound vs CPU Bound tasks, scheduling preferences

## Classical Scheduling Algorithms 
* First Come Fisrt Serves (FCFS/FIFO)
  * Based on sequence in ready queue (arrival time)
  * Simple to implement
  * Average waiting time may not be optimal (convoy effect), fairness not guaranteed
  * Always non premptive
  * No starvation possible
  * Minimal context switchings
* Priority based scheduling
  * Based on explicit priority associated with process (default / modified)
  * Typically preemptive, high prio process can preempt low prio one.
  * Designed towards real time scheduling requirements
  * Numeric value & actual priority may be proportional / inverse
  * Starvation may occur, techniques like Aging can prevent
* Round Robin
  * Each process is allowed to run for a particular time only (time slice/quantum)
  * Preempted process will go back to ready queue on timeout
  * Designed towards fairness goal
  * Higher the quantum fairness will be less
  * No.of context switchings will be more if quantum is less
  * Complete faireness not possible, if preempted process is added to ready queue before the arrival of a new process 
* Shortest Job First 
  * Allowing process whose CPu requirement is less
  * Knowing CPU requirement of waiting process is difficult/complex (future prediction/analysis)
  * Theoritical algorithm (not practical)
  * May lead to starvation
  * Assures optimal average time among processes
* Some possible comibinations
  * Pure FCFS
  * Pure RR (FCFS with time limit for each process)
  * Priority + FIFO
  * Priority + RR
* What is Priority Inversion Problem and how techniques like Priority Inheritance/Ceiling can solve this problem (self study).


## Realtime
* Deterministic Behavior
* Finite acceptable delay all the times (thus completion time also)
* Hard vs Soft realtime systems

## Multi level scheduling
* Processes may be allocated to different queues, where each queue can be associated with different scheduling policy.
* For e.g. a scheduler in mobile operating system may maintain multiple queues
  * Q1 - for telephonic tasks (real time, priority based)
  * Q2 - multimedia / games   (fairness, round robin)
  * Background tasks          (Non interactive, FIFO or RR wth larger quantum)
* A process may move across the queues, known as multi level feedback queue scheduling

## Realtime scheduling policies in Linux
* SCHED_FIFO : Priority + FIFO
* SCHED_RR   : Priority + Round Robin
* 100 priority levels in each policy
* 0 means low priority, 99 means high priority

## Time Sharing Policy in Linux
* Customized Round Robin algorithm
* 40 priority levels controlled by nice values
* Time slice / quantum proportional to priority
* Process may move among priority levels, e.g. based on aging technique priority can increase, or based on heavy CPU usage priority may go down
* Two queues per priority levels
  * Active queue : Newly created, unblocked process
  * Expired queue : preempted due to timeout (time slice/quantum expired)
* When Active queue is empty, swapping of Active & Expired queues occur
* Better faireness is assured than RR -- every process will get a chance to use CPU time before any other process takes CPU time for second time.

## Nice values
* Ranges from -20 to +19 (39 to 0 in ps output)
* Default nice value is 0 (19 as ps priority)
* Higher the nice value, lower the priority and vice versa
* -ve nice values & lowering nice values allowed by superuser only

## Scheduling in SMP
* Common Queues or Private Queues
* CPU Affinity / Pinning
* Load Balancing challenges
* Push vs Pull migration technques for load balancing
