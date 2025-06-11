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


    // Test calloc and free on calloc
    printf("------- Calloc Test -------\n");
    int *myArr2 = my_calloc(4, sizeof(int));
    
    for (int i = 0; i < 4; i++)
    {
	printf("Array index %d = %d\n", i, myArr2[i]);
    }


    // Test realloc and free on realloc
    printf("------- Realloc Test -------\n");
    int *myArr3 = my_malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++)
    {
	myArr3[i] = i;
	printf("Array index %d = %d\n", i, myArr3[i]);
    }

    myArr3 = my_realloc(myArr3, sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
    {
	printf("Array index %d = %d\n", i, myArr3[i]);
    }

    my_free(myArr);
    my_free(myArr2);
    my_free(myArr3);

    return 0;
}
