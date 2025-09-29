// fibonacci_search_no_stl.cpp
#include <cstdio>

// Utility function for min
int min(int x, int y) { return (x <= y) ? x : y; }

int fibonacciSearch(int arr[], int n, int key) {
    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib1 + fib2;

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib1 + fib2;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < key) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        } else if (arr[i] > key) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else {
            return i;
        }
    }
    
    if (fib1 && n > offset + 1 && arr[offset + 1] == key) {
        return offset + 1;
    }

    return -1;
}

// Include the merge sort functions
void mergeSort(int arr[], int left, int right); // Declaration

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int* arr = new int[n];
    for(int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = fibonacciSearch(arr, n, key);
    if (result >= 0) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found.\n");
    }
    
    delete[] arr;
    return 0;
}

// Paste the merge sort implementation here
// ...