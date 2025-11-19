/* PROGRAM TO IMPLEMENT LINER SEARCH */
# include <stdio.h>
# include <stdlib.h>
int main()
{
    int n ,key,pos,flag = 0;
    printf("Enter the size of the array : " );
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0 ; i<n ; i ++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search : " );
    scanf("%d",&key);

    // IMPLEMENTING SEARCHING
    for (int i = 0 ; i<n ; i ++)
    {
        if(arr[i] == key)
        {
            flag = 1;
            pos = i+1;
            break;
        }
    }
    if(flag)
    {
        printf("Element %d found at position: %d",key,pos);
    }
    else{
        printf("Element %d not found !!",key);
    }
    return 0;
}
