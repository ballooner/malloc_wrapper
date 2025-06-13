#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <assert.h>

// Defines
#define HEAP_CAPACITY 65536
#define MEMORY_DATA_CAPACITY 32786

// Data definitions
typedef struct {
    size_t block_size;
    void* block_address;
    bool is_used;
} memory_block_t;

void* heap;
size_t heap_size = 0;
memory_block_t allocated_blocks_list[MEMORY_DATA_CAPACITY];
size_t allocated_blocks = 0;
memory_block_t free_blocks_list[MEMORY_DATA_CAPACITY];
size_t free_blocks = 1;

void* heap_alloc(size_t size)
{
    assert(size < HEAP_CAPACITY);

    void* memory = (void*)((char*)heap + heap_size);
    heap_size += size;

    memory_block_t memoryBlock = 
    {
	.block_size = size,
	.block_address = memory,
	.is_used = true,
    };
    allocated_blocks_list[allocated_blocks++] = memoryBlock;

    return memory;
}

//Unimplemented
void heap_dealloc(void* memory)
{
}

int main(void)
{
    // Initialize simulated heap and add block to free list
    heap = mmap(NULL, HEAP_CAPACITY, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (heap == MAP_FAILED)
    {
	printf("mmap failed to allocate heap. Exiting...\n");
	exit(1);
    }

    char* alphabet = (char*)(heap_alloc(sizeof(char) * 26));
    for (int i = 0; i < 26; i++)
    {
	*(alphabet + i) = i + 'a';
	putchar(*(alphabet + i));
    }
    putchar('\n');

    return 0;
}
