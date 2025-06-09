#include "my_malloc.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void* my_malloc_debug(size_t size, char *calledFrom, int line)
{
    void *mem;
    if ((mem = malloc(size)) == NULL)
	exit(1);

    printf("[malloc] %zu bytes at %p from %s:%d\n", size, mem, calledFrom, line);

    return mem;
}


void* my_calloc_debug(size_t n, size_t size, char *calledFrom, int line)
{
    if (n == 0 || size == 0)
	return NULL;

    size_t mem_size = n * size;
    void *mem = malloc(mem_size);

    memset(mem, 0, mem_size);

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
    printf("[free] %p from %s:%d\n", mem, calledFrom, line);
    free(mem);
}
