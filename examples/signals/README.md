# Signals

## Discussion & Concept Checking
* Signals overview
* Sender process, target process
* Signal pending bits (pending field) in process desriptor/PCB
* Signal maks bit (mask field) in process desriptor/PCB
* Signal handler table (per process)
* Signals involved in common actions
  * Key strokes : Ctrl + C, Ctrl + \, Ctrl + Z
  * Child process termination
  * Resuming suspended process
  * Floating point exception
  * Segmentation fault
* Running a process in background with & suffix
* Default signal handler, their behavior
* Register customer handlers
* Non maskable signals - SIGKILL & SIGSTOP
* Do custom handlers applicable for non maskable signals?
* Commands for generating signals
* Commands for job control
* APIs for genearting & handling signals

## Commands
```
kill -l
kill <pid>
kill -9 <pid>
kill -? <pid>       # replace with ?  any signal number or symbol like SIGxxx

killall <pid>
pkill -? <pid>

fg
bg
jobs

```

## APIs
* signal, pause, kill, raise, alarm
* other - sigaction, sigsuspend, sigprocmask

#### Examples
* Simple example of custom handling [code](code/sigdemo.c)
