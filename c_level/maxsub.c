#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int findCrossingSum(int* arr, int low, int high, int mid){
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;

    for(int i = mid; i >= low; i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid + 1;

    for(int i = mid + 1; i <= high; i++){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }

    return left_sum + right_sum;
}

int find_max_sub(int* arr, int low, int high){
    if(low == high) return arr[low]; 

    int mid = (low + high) / 2;

    int left_sum = find_max_sub(arr, low, mid);
    int right_sum = find_max_sub(arr, mid + 1, high);
    int mid_crossing = findCrossingSum(arr, low, high, mid);

    return max(left_sum, max(right_sum, mid_crossing));
}

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_sum = find_max_sub(arr, 0, n - 1);
    printf("Maximum subarray sum is: %d\n", max_sum);

    return 0;
}

