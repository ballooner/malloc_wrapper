# Memory Allocator with a Custom Heap
This project is an improvement on my previous project on branch "malloc-wrapper".
It is intended to go deeper into how a malloc call would actually work on a system.

## Features
- Custom heap that will be used to store malloc'd data and the
    pointers to the data
- Custom malloc, calloc, realloc and free that will interact with
    the custom heap. 
- A way to handle the internal fragmentation of the heap i.e memory coalescing.

### File Overview

