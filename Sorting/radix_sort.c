/* PROGRAM TO IMPLEMENT RADIX SORT */
# include <stdio.h>
# include <stdlib.h>

int getMax(int arr[] , int n)
{
    int max = arr[0];
    for(int i = 0 ; i< n ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}


void countingSort(int arr[] , int n , int exp)
{
    int output[n];
    int bucket[10] = {0};
    for(int i = 0 ; i<n ; i++)
    {
        bucket[(arr[i] /exp ) %10]++;
    }
    for(int i = 1 ; i<10 ; i++)
    {
        bucket[i] += bucket[i-1];
    }
    for(int i = n-1 ; i>= 0 ; i--)
    {
        int digit = (arr[i]/exp)%10;
        output[bucket[digit]-1] = arr[i];
        bucket[digit]--;
    }
    for(int i =0 ; i<n ; i++)
    {
        arr[i] = output[i];
    }

}
void radixSort(int arr[] ,int n)
{
    int max = getMax(arr,n);
    for(int exp = 1 ; max/exp > 0 ; exp*=10)
        countingSort(arr,n,exp);
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
    radixSort(array,n);
    printf("\n");
    printf("The Sorted array :\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d   ",array[i]);
    }
    return 0;
}