/* PROGRAM TO IMPLEMENT QUICK SORT */
# include <stdio.h>
# include <stdlib.h>

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[] , int low , int high)
{
    int pivot = arr[low];
    int i = low+1 , j = high;
    while(1)
    {
        while(i<= high && arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
        {
            swap(&arr[i] , &arr[j]);
        }
        else
            break;
    }
    swap(&arr[low], &arr[j]);
    return j ;
}

void quickSort(int arr[],int low , int high)
{
    if(low < high)
    {
    int pi = partition(arr , low , high);
    quickSort(arr, low , pi-1);
    quickSort(arr, pi+1 ,high);
    }
}


int main()
{
    int n ;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr [n];
    printf("\nEnter the array elements : ");
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);
        
    printf("\nArray before quick sort : ");
    for(int i = 0 ; i < n ; i++)
        printf("%d   ",arr[i]);
    quickSort(arr , 0 , n-1);
    printf("\n");
    printf("\nArray after quick sort : ");
    for(int i = 0 ; i < n ; i++)
        printf("%d   ",arr[i]);
    return 0;
}