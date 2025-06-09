#include "my_malloc.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void* my_malloc_debug(size_t size, char *calledFrom, int line)
{
    size_t totalSize = size + sizeof(size_t);

    void *mem;
    if ((mem = malloc(totalSize)) == NULL)
	exit(1);

    //Store the size of block
    *((size_t*)mem) = size;
    //Move pointer to after metadata
    mem = (void*)((char*)mem + sizeof(size_t));

    printf("[malloc] %zu bytes at %p from %s:%d\n", size, mem, calledFrom, line);

    return mem;
}


void* my_calloc_debug(size_t n, size_t size, char *calledFrom, int line)
{
    if (n == 0 || size == 0)
	return NULL;

    size_t mem_size = (n * size) + sizeof(size_t);
    void *mem;
    if ((mem = malloc(mem_size)) == NULL)
	exit(1);

    *((size_t*)mem) = size * n;
    mem = (void*)((char*)mem + sizeof(size_t));

    memset(mem, 0, mem_size - sizeof(size_t));

    printf("[calloc] %zu elements of %zu bytes allocated at %p and zeroed from %s:%d\n",
	    n, size, mem, calledFrom, line);

    return mem;
}
/*
void* my_realloc_debug(void *mem, size_t size, char *calledFrom, int line)
{
}
*/

void my_free_debug(void *mem, char *calledFrom, int line)
{
    size_t size = *((char*)mem - sizeof(size_t));
    mem = (void*)((char*)mem - sizeof(size_t));

    printf("[free] %zu bytes at %p from %s:%d\n", size, mem, calledFrom, line);
    free(mem);
}
