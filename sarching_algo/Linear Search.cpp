// linear_search_no_stl.cpp
#include <cstdio>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = new int[n]; // Dynamically allocate memory
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    int index = linearSearch(arr, n, key);

    if (index != -1) {
        printf("Key found at index: %d\n", index);
    } else {
        printf("Key not found.\n");
    }

    delete[] arr; // Free the allocated memory
    return 0;
}