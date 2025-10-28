/* PROGRAM TO IMPLEMENT BUBBLE SORT */
# include <stdio.h>
# include <stdlib.h>
void bubbleSort(int n , int arr[])
{
    int temp;
    for(int i = 0 ; i< n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(arr[j]> arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    bubbleSort(n,array);
    printf("\n");
    printf("The Sorted array :\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d   ",array[i]);
    }
}