# Memory Allocator with a Custom Heap
This project is an improvement on my previous project on branch "malloc-wrapper".
It is intended to go deeper into how a malloc call will actually work on a system
and help me understand more of the intricacies of the C language.

## Features
- Custom heap array that will be used to store malloc'd data and the
    pointers to the data
- Custom malloc, calloc, realloc and free that will interact with
    the custom heap. These implementations will allow dynamically sized memory.
- Garbage collector that will iterate through the heap (and maybe the stack)
    to find all the allocated blocks of memory in the heap, and the space
    that is unused
- A way to handle the internal fragmentation of the heap i.e memory coalescing.

### File Overview

