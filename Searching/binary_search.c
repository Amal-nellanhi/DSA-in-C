/* PROGRAM TO IMPLEMENT BINARY SEARCH */
# include <stdio.h>
void main ()
{
    int n , i ,pos, flag = 0,mid ,key;
    printf("Enter the size of the array : " );
    scanf("%d",&n);
    int arr[n];
    int low = 0 ,high = n-1;
    printf("Enter the array elements in ascending order : ");
    for (i = 0 ; i<n ; i ++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search : " );
    scanf("%d",&key);
    while(low<= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            flag = 1 ;
            pos = mid +1;
            break ;
        }
        else if (key > arr[mid])
            low = mid +1;
        else
            high = mid-1;
    }
    if (flag)
        printf("Element found at %d position",pos);
    else
        printf("Element not found !!");
        
}
