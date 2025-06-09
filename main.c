#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define my_malloc(x) my_malloc_debug(x, __FILE__, __LINE__)
#define my_calloc(x, y) my_calloc_debug(x, y, __FILE__, __LINE__)
#define my_realloc(x, y) my_realloc_debug(x, y, __FILE__, __LINE__)
#define my_free(x)   my_free_debug(x, __FILE__, __LINE__)

void *my_malloc_debug(size_t size, char *calledFrom, int line);
void *my_calloc_debug(size_t n, size_t size, char *calledFrom, int line);
void *my_realloc_debug(void *mem, size_t size, char *calledFrom, int line);
void my_free_debug(void *mem, char *calledFrom, int line);

int main(void)
{
    int *myArr = my_malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++)
    {
	myArr[i] = 10 + i;
    }

    for (int i = 0; i < 4; i++)
    {
	printf("Array index %d (at address: %p) = %d\n", i, myArr + i, myArr[i]);
    }

    my_free(myArr);

    return 0;
}

void *my_malloc_debug(size_t size, char *calledFrom, int line)
{
    void *mem;
    if ((mem = malloc(size)) == NULL)
	exit(1);

    printf("[malloc] %zu bytes at %p from %s:%d\n", size, mem, calledFrom, line);

    return mem;
}

void *my_calloc_debug(size_t n, size_t size, char *calledFrom, int line)
{
}

void *my_realloc_debug(void *mem, size_t size, char *calledFrom, int line)
{
}

void my_free_debug(void *mem, char *calledFrom, int line)
{
    printf("[free] %p from %s:%d\n", mem, calledFrom, line);
    free(mem);
}
