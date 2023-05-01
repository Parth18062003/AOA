#include <stdio.h> 
int partition (int a[], int start, int end) { 
    int pivot = a[end]; // pivot element 
    int i = (start - 1); 
    for (int j = start; j <= end - 1; j++) { 
        if (a[j] < pivot) { 
            i++; 
            int t = a[i]; 
            a[i] = a[j]; 
            a[j] = t; 
        } 
    } 
    int t = a[i+1]; 
    a[i+1] = a[end]; 
    a[end] = t; 
    return (i + 1); 
} 

void quick(int a[], int start, int end) { 
    if (start < end) { 
        int p = partition(a, start, end); 
        quick(a, start, p - 1); 
        quick(a, p + 1, end); 
    } 
} 

void main() { 
    int n,i; 
    printf("Parth Kadam 27, D6AD\n Quick Sort\n");
    printf("Enter number of elements in array: "); scanf("%d",&n); 
    int a[n]; 
    printf("Enter elements to be sorted: "); for(i=0;i<n;i++) { 
        scanf("%d",&a[i]); 
    }
    printf("Unsorted Array\n"); 
    for(i=0;i<n;i++) { 
        printf(" %d",a[i]); 
    } 
    quick(a, 0, n - 1); 
    printf("\nSorted Array\n"); 
    for(i=0;i<n;i++) { 
        printf(" %d",a[i]); 
    } 
} 
