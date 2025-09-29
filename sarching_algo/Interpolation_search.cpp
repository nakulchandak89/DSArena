// interpolation_search_no_stl.cpp
#include <cstdio>

// Include the merge sort functions
void mergeSort(int arr[], int left, int right); // Declaration

int interpolationSearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right && key >= arr[left] && key <= arr[right]) {
        if (left == right) {
            if (arr[left] == key) return left;
            return -1;
        }
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (key - arr[left]));
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) left = pos + 1;
        else right = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = new int[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    int index = interpolationSearch(arr, n, key);
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