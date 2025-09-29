// ternary_search_no_stl.cpp
#include <cstdio>

// Include the merge sort functions from above or in a header file
void mergeSort(int arr[], int left, int right); // Declaration

int ternarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;

        if (key < arr[mid1]) right = mid1 - 1;
        else if (key > arr[mid2]) left = mid2 + 1;
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    int index = ternarySearch(arr, n, key);
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