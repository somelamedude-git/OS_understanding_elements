#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

void swap(int* a, int* b);

int partition(int arr[], int l, int r) {
    int x = arr[r];
    int i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kthsmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);

        if (index - l == k - 1)
            return arr[index];

        if (index - l > k - 1)
            return kthsmallest(arr, l, index - 1, k);

        return kthsmallest(arr, index + 1, r, k - index + l - 1);
    }
    return INT_MAX;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, k;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    printf("Generated array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter k: ");
    scanf("%d", &k);

    int result = kthsmallest(arr, 0, n - 1, k);
    if (result == INT_MAX)
        printf("Invalid k\n");
    else
        printf("%d-th smallest element = %d\n", k, result);

    free(arr);
    return 0;
}

