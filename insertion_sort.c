#include <stdio.h>
#include <math.h>

void main()
{
    int n,i;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements to be sorted: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted Array\n");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    
    int key, j;
    for (i=1;i<n;i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
}

