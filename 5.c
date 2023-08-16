#include <stdio.h>
#include <stdlib.h>

int a[20], i, j, l, u, n, p, loc;

void quicksort(int a[], int lb, int ub);
int partition(int a[], int lb, int ub);

void main() {
    printf("enter the number of elements : \n");
    scanf("%d", &n);
    printf("enter the %d elements : \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}

void quicksort(int a[], int lb, int ub) {
    if (lb < ub) {
        loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

int partition(int a[], int lb, int ub) {
    p = lb;
    int start = lb + 1; // Start with the element next to pivot
    int end = ub;
    
    while (start <= end) {
        while (a[start] <= a[p] && start <= ub) {
            start++;
        }
        while (a[end] > a[p]) {
            end--;
        }
        if (start < end) {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    // Swap pivot with element at 'end' position
    int temp = a[p];
    a[p] = a[end];
    a[end] = temp;
    
    return end;
}
