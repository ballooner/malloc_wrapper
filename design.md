# Simple Malloc Wrapper
This project was initially started as a way to get start understanding memory
management, as a lot of the details are typically hidden from the user. This
project iteration is just a basic wrapper of malloc,calloc,realloc,free without
any advanced techniques.

## Implementation
Since this is my first iteration of the project I didn't get too deep in 
management techniques and just implemented basic wrappers and a dynamic array
to store allocated memory and handle memory that hasn't been 
de-allocated on exit, I didn't implement things like:
- Free-space management
- Fragmentation
- Paging

This version is located at:


### File Overview
- my_malloc.h -> contains function/struct definitions for the implementation.
- my_malloc.c -> contains the functionality of the wrappers.
- test_malloc.c -> contains simple testing and can serve as an example on using
                   the wrapper.

### Future Plans
For future iterations of this project (located in branches) I plan on
implementing:
- Management of a fixed (or expandable?) memory area from mmap.
- Free-space tracking and block reuse
- Fragmentation handling and block coalescing
- Fixed-size paging (maybe dynamic size pages)
