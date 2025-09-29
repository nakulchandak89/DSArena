// exponential_search_no_stl.cpp
#include <cstdio>

// Helper binary search
int binarySearchHelper(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int key) {
    if (n == 0) return -1;
    if (arr[0] == key) return 0;

    int i = 1;
    while (i < n && arr[i] <= key) {
        i = i * 2;
    }
    
    int rightBound = (i < n) ? i : n - 1;
    return binarySearchHelper(arr, i / 2, rightBound, key);
}


// Include the merge sort functions
void mergeSort(int arr[], int left, int right); // Declaration

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = new int[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    int index = exponentialSearch(arr, n, key);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found.\n");
    }

    delete[] arr;
    return 0;
}

// Paste the merge sort implementation here
// ...