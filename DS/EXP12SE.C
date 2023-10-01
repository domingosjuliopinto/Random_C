//Program for binary search
#include<stdio.h>
#include<conio.h>

int binary_search(int arr[], int val, int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low<=high)
    {
	mid = (low+high)/2;
	if(val == arr[mid])
	{
	    return mid+1;
	}
	else
	{
	    if(val > arr[mid])
	    {
		low = mid + 1;
	    }
	    else if(val < arr[mid])
	    {
		high = mid - 1;
	    }
	}

    }
    return -1;
}

void main()
{
    int i, n, arr[50], val, pos;
	clrscr();
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    printf("Enter the arrays element in ascending order: \n");
    for (i = 0; i < n; i++)
    {
	scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &val);
    pos = binary_search(arr, val, n);
    if(pos != -1)
	printf("The element is present at position: %d", pos);
    else
	printf("Element not present in the array");
    getch();
}