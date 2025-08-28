#include <stdio.h>
#include <stdlib.h>


int binarySearch(int* A, int left, int right, int num){
	int middle = (right+left)/2;
	if(A[middle] == num){
		return middle;
	}

	if(left>right) return -1;

	if(num > A[middle]) return binarySearch(A, middle+1, right, num);
	return binarySearch(A, left, middle-1, num);
}


int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;

    int index = binarySearch(arr, 0, n-1, target);

    if(index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}
	
