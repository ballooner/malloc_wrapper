#include "my_malloc.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

static memory_block_t* memoryList;
static int blocksAllocated = 0;

static void addToMemoryList(void *mem, size_t size)
{
    blocksAllocated++;

    if ((memoryList = realloc(memoryList, sizeof(memory_block_t) * blocksAllocated)) == NULL)
        exit(1);

    memory_block_t memoryBlock = 
        {
            .blockSize = size,
            .memoryAddress = mem
        };

    memoryList[blocksAllocated - 1] = memoryBlock;
}

static void removeFromMemoryList(void *mem)
{
    if (mem == memoryList[blocksAllocated - 1].memoryAddress)
    {
        memoryList = realloc(memoryList, (sizeof(memory_block_t) * blocksAllocated) - sizeof(memory_block_t));
        blocksAllocated--;

        return;
    }

    // Find memory in list and save address
    int indexAt;
    for (int i = 0; i < blocksAllocated; i++)
    {
        if (mem == memoryList[i].memoryAddress)
        {
            indexAt = i;
            break;
        }
    }

    // Swap the last index with the index to be removed
    // then reallocate memory list without it's last index
    memoryList[indexAt] = memoryList[blocksAllocated - 1];
    blocksAllocated--;
    memoryList = realloc(memoryList, sizeof(memory_block_t) * blocksAllocated);
}

void clearMemoryOnExit(void)
{
    if (blocksAllocated == 0)
    {
        exit(0);
    }

    for (int i = 0; i < blocksAllocated; i++)
    {
        void *address = memoryList[i].memoryAddress;
        printf("[clearMemoryOnExit] freeing unfreed %p of %zu bytes\n", address, memoryList[i].blockSize);
        free(address);
    }
}

void* my_malloc_debug(size_t size, char *calledFrom, int line)
{
    size_t totalSize = size + sizeof(size_t);

    void *mem;
    if ((mem = malloc(totalSize)) == NULL)
    {
	    exit(1);
    }

    addToMemoryList(mem, size);

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
    {
	    return NULL;
    }

    size_t mem_size = (n * size) + sizeof(size_t);
    void *mem;
    if ((mem = malloc(mem_size)) == NULL)
    {
	    exit(1);
    }

    addToMemoryList(mem, n * size);

    *((size_t*)mem) = size * n;
    mem = (void*)((char*)mem + sizeof(size_t));

    memset(mem, 0, mem_size - sizeof(size_t));

    printf("[calloc] %zu elements of %zu bytes allocated at %p and zeroed from %s:%d\n",
	    n, size, mem, calledFrom, line);


    return mem;
}

void* my_realloc_debug(void *mem, size_t size, char *calledFrom, int line)
{
    // Get size of memory block and find the smaller of two sizes
    size_t oldSize = *((char*)mem - sizeof(size_t));
    size_t minSize = oldSize > size ? size : oldSize;

    void *newBlock;
    if ((newBlock = malloc(size + sizeof(size_t))) == NULL)
    {
	    exit(1);
    }

    addToMemoryList(newBlock, size);

    *((size_t*)newBlock) = size;
    newBlock = (void*)((char*)newBlock + sizeof(size_t));

    memcpy(newBlock, mem, minSize);

    printf("[realloc] %p moved to %p and changed from %zu bytes to %zu bytes,\n"
	    "wrote %d elements to new block from %s:%d\n", mem, newBlock, oldSize, size, (int)(minSize / sizeof(*mem)), calledFrom, line); 

    my_free(mem);

    return newBlock;
}

void my_free_debug(void *mem, char *calledFrom, int line)
{

    void* memAddress = mem;
    size_t size = *((char*)mem - sizeof(size_t));
    mem = (void*)((char*)mem - sizeof(size_t));

    // Make sure that memory provided is valid
    bool memoryInList = false;
    for (int i = 0; i < blocksAllocated; i++)
    {
        if (mem == memoryList[i].memoryAddress)
        {
            memoryInList = true;
            break;
        }
    }

    if (memoryInList == false)
    {
        printf("[free] Memory (%p) provided is not valid\n", mem);
        exit(1);
    }


    removeFromMemoryList(mem);

    printf("[free] %zu bytes at %p from %s:%d\n", size, memAddress, calledFrom, line);
    free(mem);
}
