# Memory management with simulated RAM structure
This is the second iteration of my memory management project and it will start
to dive into how a simple OS may handle a memory space.

## Features
- Allocation of a set size of memory using mmap() to simulate RAM.
- A way to create a fake process that will allocate a random number of bytes
    to be stored in the allocated RAM structure and then die after a short 
    period of time.
- A free list that keeps track of the available memory space we can allocate to 
    a process.
- Memory coalescing so we can deal with memory fragmentation.
- Logging for:
    - Memory allocation
    - Memory deallocation 
    - Process creation
    - Defragmentation time
- Program arguments to change how often processes get created, 
    how much memory they will allocate and ability to write log to a text file.

### File Overview

