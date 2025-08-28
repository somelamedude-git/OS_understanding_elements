#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* find_min_max(int* arr, int* ans_arr, int low, int high) {
    if (low == high) {
        if (ans_arr[0] == -1 || arr[low] < ans_arr[0]) 
            ans_arr[0] = arr[low];
        if (ans_arr[1] == -1 || arr[low] > ans_arr[1]) 
            ans_arr[1] = arr[low];
        return ans_arr;
    }

    if (high == low + 1) {
        int min_val, max_val;

        if (arr[low] < arr[high]) {
            min_val = arr[low];
            max_val = arr[high];
        } else {
            min_val = arr[high];
            max_val = arr[low];
        }

        if (ans_arr[0] == -1 || min_val < ans_arr[0]) 
            ans_arr[0] = min_val;
        if (ans_arr[1] == -1 || max_val > ans_arr[1]) 
            ans_arr[1] = max_val;

        return ans_arr;
    }

    int mid = (low + high) / 2;
    ans_arr = find_min_max(arr, ans_arr, low, mid);
    ans_arr = find_min_max(arr, ans_arr, mid + 1, high);

    return ans_arr;
}

int main() {
    clock_t start, end;
    double cpu_time_used;    
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int ans[2] = {-1, -1};
    start = clock();
    int* result = find_min_max(arr, ans, 0, 7);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("%d, %d\n", result[0], result[1]);
    printf("%f ", cpu_time_used);
    return 0;
}

