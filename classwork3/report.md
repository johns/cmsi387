## Classwork 3: Process-C-ing
#### Marissa Alvarez, Daniel Luna, Merci Magallanes, Sam Savini, and John Scott


### Problem 1 - `fork_wait.c`
1. Bash command: `ps -el | more`. You can tell which is the parent according to the PPID column because the child’s PPID matches the parent’s PID.

2. PID of bash terminal: `5629`. Tree: `bash───a.out───a.out`

3. Result was: `15`

  `[1]+  Exit 126 ./arrested_dev.c`

### Problem 2 - `fork_count.c`
1. 4 processes are created during `fork_count.c`'s execution.

2. Not done yet...

### Problem 3 - `fork_exec_print.c`
No, it will not be printed because the `execlp` call following the `fork()` call spawns a new process, in which the current child process from the `fork()` is replaced by the new `ls` program file from the `execlp` call’s execution.

### Problem 4 - `fork_mem.c`
1. Before running `fork_mem.c` I consider the fact that the Parent does not have a value and since the PID is forked then we will have children. Since, the PID equals 0 then it runs through the if statement and the parent runs through the else if.

2. After, running `fork_mem.c` our considerations about the program made sense and reassured our reasoning. Since it is not in the same scope as the child's, it will all return the value of zero.     
Output: `PARENT: svar=0, lvar=0, dvar=0`

### Problem 5 - `forkonacci.c`
```c
Put forkonacci.c here...
```

### Problem 6 - `fork_bomb.c`
The `while(1)` in `fork_bomb.c` will loop indefinitely until told explicitly to stop. This will continue to allocate uninitialized memory storage to new forks until the computer runs out of memory. When the computer finally runs out of memory, the processes taking place on the computer will freeze completely until that memory is freed.
