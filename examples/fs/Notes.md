# Notes

## FileSystem
* Some implementations - FAT32, NTFS, ext4, xfs, reiserfs, zfs and many more
* Pseudo file systems - procfs, sysfs, devfs, tmpfs
* File System Layout 
    * Boot block
    * Super block
    * I-Node blocks
    * Data blocks
* Virtual File System(VFS) - Gateway of all other file systems

## Hard links and soft links
* i-node link/ref count
* Limitations of hard links
  * Not applicable for directories
  * Not applicable across directories
* How to idenitfy symlinks
* Target path of symlink, broken symlinks

## Pipes
* Meant for data exchange (IPC)
* Pseudo files (no data blocks)
* Data stored in the form of kernel buffers (pipefs)
* Strictly FIFO based, stream of data (not descrete(
* Opened by two processes - one for reading, other for writing
* Reading an empty pipe, writing into full pipe is a blocking call by default  
* Unnamed Pipes
  * No file name / PATH applicable (No disk i-node)
  * Applicable for related processes only
* Named Pipes (FIFOs)
  * Associated with file name / PATH (but still no data blocks)
  * Applicable for any two processes

## System calls
* open, read, write, close
* lseek
* mkdir
* rmdir
* chdir, fchdir
* getcwd
* unlink
* rename
* symlink
* readlink
* chmod, fchmod
* chown, fchwon
* stat, lstat, fstat
* dup, dup2

## Additional - workflow of open, read/write, close
* open system call
  * identiies first free entry in open fd table
  * locate disk i-node of target file (path lookup)
  * copy disk inode into in core i-node (common table for all processes)
  * fill address of in core i-node in identified free entry of open fd table
  * return the index of filled entry to user space
  * error if fd table is full (resource limit), invalid path/permissions
* additional fields in open fd table entries - mode of operation, offset
* read/write system call
  * lookup open fd table with file descriptor index
  * refer in core i-node as per available address
  * perform read/write operations as per attributes of in-core i-node
* close system call
  * lookup open fd table with given index and identify in core i-node
  * sync up in core i-node with disk i-node
  * release in core i-node if no more active references from other processes
  * mark entry in fd table as free (marked for re use)
* path lookup
  * directory file holds name vs i-node mapping of all files & subdirs (catalogue)
  * i-node no.of root dir is 2
  * lookup i-node of root dir, and read data blocks (i-node no.s of sub dirs) 
  * with the help of i-node no of each sub dir, fetch i-node nos of next level sub dirs
  * from last subdir, fetch i-node number of target file

## Additional - dup system call & use cases
* Copies fd table entry into first free entry
* Implementation of `command > file`
  * Create a child process
  * fd = open file in write mode by child process
  * close(1) - close stdout entry in child process
  * dup(fd)
  * launch command in child using execl family of functions
  * Parent wait for completion of child process
* Implementation of `command < file`
* Implementation of `command1 | command2`
  * Create an unnamed pipe
  * Create two child processes
  * In child-1 
    * close stdout, dup write end of pipe
    * launch command1 using execl
  * In child-2
    * close stdin, dup read end of pipe
    * launch command1 using execl
  * Parent wait for completion of both child processes
  



