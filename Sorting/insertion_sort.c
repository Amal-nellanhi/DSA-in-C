/* PROGRAM TO IMPLEMENT INSERTION SORT */
# include <stdio.h>
# include <stdlib.h>
void insertionSort(int n , int arr[])
{
    int key ,j;
    for(int i = 1 ; i< n ; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j>= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;
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
    insertionSort(n,array);
    printf("\n");
    printf("The Sorted array :\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d   ",array[i]);
    }
    return 0;
}