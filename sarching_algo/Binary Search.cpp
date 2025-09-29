// binary_search_no_stl.cpp
#include <cstdio>

// Include the merge sort functions from above or in a header file
void mergeSort(int arr[], int left, int right); // Declaration

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    // Binary search requires a sorted array
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key);

    if (index != -1) {
        printf("Key found at index %d\n", index);
    } else {
        printf("Key not found\n");
    }
    
    delete[] arr;
    return 0;
}

// Paste the merge sort implementation (merge and mergeSort functions) here
// ...