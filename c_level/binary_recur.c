#include <stdio.h>
#include <stdlib.h>

int recursiveSearch(int* arr, int low, int high, int target) {
    if (low > high) return -1;  

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return recursiveSearch(arr, low, mid - 1, target);
    else
        return recursiveSearch(arr, mid + 1, high, target);
}

int main() {
    int arr[] = {2, 4, 7, 9, 12, 17, 23, 31, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 17;
    int result = recursiveSearch(arr, 0, size - 1, target);

    if (result != -1)
        printf("Found %d at index %d\n", target, result);
    else
        printf("Not found\n");

    return 0;
}

