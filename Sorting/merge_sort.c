/* PROGRAM TO IMPLEMENT MERGE SORT */
# include <stdio.h>
# include <stdlib.h>

void MERGE(int arr[] , int left , int right , int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1] , R[n2];
    for(int i = 0 ; i < n1 ; i++)
        L[i] = arr[left + i];
    for(int j = 0 ; j < n2 ; j++)
        R[j] = arr[mid+1+j];
    int i = 0 , j = 0 , k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(i < n2)
        arr[k++] = R[j++];

}
void mergeSort(int arr[] , int left , int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        MERGE(arr,left,right,mid);
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
    mergeSort(array,0,n-1);
    printf("\n");
    printf("The Sorted array :\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d   ",array[i]);
    }
}