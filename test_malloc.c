#include <stdio.h>
#include <stdlib.h>
#include "my_malloc.h"

int main(void)
{
    // Test malloc and free on malloc
    int *myArr = my_malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++)
    {
	myArr[i] = 10 + i;
	printf("Array index %d = %d\n", i, myArr[i]);
    }

    my_free(myArr);

    // Test calloc and free on calloc
    myArr = my_calloc(4, sizeof(int));
    
    for (int i = 0; i < 4; i++)
    {
	printf("Array index %d = %d\n", i, myArr[i]);
    }

    my_free(myArr);

    return 0;
}
