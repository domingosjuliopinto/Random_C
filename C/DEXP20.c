//To modify element of an array using pointers.
#include<stdio.h>

int main()
{
    int arr[5] = {100, 200, 300, 400, 500}, i;
    int *ptr = arr;

    printf("Array before modification: \n");
    for(i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n",i,*(ptr+i));
    }

    //changing 3rd element(300) as 1000.
    *(ptr+2) = 1000;

    printf("\nArray after modification: \n");
    for(i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n",i,*(ptr+i));
    }
    return 0;
}