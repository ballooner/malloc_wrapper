#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stddef.h>

#define my_malloc(x) my_malloc_debug(x, __FILE__, __LINE__)
#define my_calloc(x, y) my_calloc_debug(x, y, __FILE__, __LINE__)
#define my_realloc(x, y) my_realloc_debug(x, y, __FILE__, __LINE__)
#define my_free(x)   my_free_debug(x, __FILE__, __LINE__)

typedef struct memory_block
{
    size_t blockSize;
    void* memoryAddress;
} memory_block_t;

void initializeMemoryManager();
void* my_malloc_debug(size_t size, char *calledFrom, int line);
void* my_calloc_debug(size_t n, size_t size, char *calledFrom, int line);
void* my_realloc_debug(void *mem, size_t size, char *calledFrom, int line);
void my_free_debug(void *mem, char *calledFrom, int line);

#endif
