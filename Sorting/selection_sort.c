/* PROGRAM TO IMPLEMENT THE SELECTION SORT ALGORITHM */
# include <stdio.h>
# include <stdlib.h>

void selectionSort(int n , int arr[])
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        int minIdx = i;
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

int main()
{
    int n ;
    printf("Enter the number of elements : \n");
    scanf("%d",&n);
    int array[n];
    printf("Enter the array elements : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("The original array :\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d   ",array[i]);
    }
    selectionSort(n,array);
    printf("\n");
    printf("The Sorted array :\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d   ",array[i]);
    }
    return 0;
}