#include<stdio.h>

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
    int j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min])
            min = j;
        if(min!=i)
            {
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
    }
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
}