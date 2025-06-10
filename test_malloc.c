#include <stdio.h>
#include <stdlib.h>
#include "my_malloc.h"

int main(void)
{
    // Test malloc and free on malloc
    printf("------- Malloc Test -------\n");
    int *myArr = my_malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++)
    {
	myArr[i] = 10 + i;
	printf("Array index %d = %d\n", i, myArr[i]);
    }

    my_free(myArr);

    // Test calloc and free on calloc
    printf("------- Calloc Test -------\n");
    myArr = my_calloc(4, sizeof(int));
    
    for (int i = 0; i < 4; i++)
    {
	printf("Array index %d = %d\n", i, myArr[i]);
    }

    my_free(myArr);

    // Test realloc and free on realloc
    printf("------- Realloc Test -------\n");
    myArr = my_malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++)
    {
	myArr[i] = i;
	printf("[Before] Array index %d = %d\n", i, myArr[i]);
    }

    myArr = my_realloc(myArr, sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
    {
	printf("Array index %d = %d\n", i, myArr[i]);
    }

    my_free(myArr);

    return 0;
}
