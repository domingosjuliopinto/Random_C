//Program to implement Merge Sort and Quick Sort
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int num;
int arr[100];

void display()
{   int i;
    for(i = 0 ; i < num ; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int low, int mid, int high)
{
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l[100], r[100];
    for(i = 0 ; i < n1 ; i++)
    {
	l[i] = arr[low + i];
    }
    for(j = 0 ; j < n2 ; j++)
    {
	r[j] = arr[mid + j + 1];
    }
    l[n1] = 100;
    r[n2] = 100;
    i = 0, j = 0;
    k = low;
    for(; k < high ; k++)
    {
        if(l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
    }
    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid+1, high);
        merge(low, mid, high);
        printf("low= %d mid= %d high= %d\n", low, mid, high);
        display();
    }
}

int partition(int low, int high)
{
    int j,temp;
    int pivot = arr[high];
    int i = low - 1;
    for(j = low ; j <= high - 1 ; j++)
    {
	if(arr[j] <= pivot)
	{
	    i++;
	    temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	}
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quick_sort(int low, int high)
{
    if(low < high) 
    {
        int p = partition(low, high);
        printf("pivot_index= %d, pivot_element= %d\n", p, arr[p]);
        display();
        quick_sort(low, p-1);
        quick_sort(p+1, high);
    }
}

void main()
{
    int choice,i;
    clrscr();
    srand(time(0));
    printf("How many numbers?? ");
    scanf("%d", &num);
    printf("Given Array: ");
    for(i = 0 ; i < num ; i++)
    {
        arr[i] = rand()%100;
        printf("%d ", arr[i]);
    }
    printf("\n1.Merge Sort\n2.Quick Sort\nEnter anything to exit \nEnter choice?? ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        merge_sort(0, num-1);
        break;
    case 2: 
        quick_sort(0, num-1);
        break;
    default:
        break;
    }
	getch();
}
