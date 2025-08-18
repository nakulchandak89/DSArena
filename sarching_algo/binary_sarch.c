#include<stdio.h>
// this script is for the binary search algo
// actully this algo is working on the sorted data only so we use merge sort to sort and then the array is passed to the sarching algo 
void mergesort(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) { // Fixed condition
        if (L[i] < R[j]) {
            arr[k] = L[i]; // Fixed assignment
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort_array(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sort_array(arr, left, mid);
        sort_array(arr, mid + 1, right);

        mergesort(arr, left, mid, right); // Corrected function name
    }
}

int main() {
    int n;
    printf("Enter the number of the array present in the element: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the data of index %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    sort_array(arr, 0, n - 1); // Corrected function name

    int left = 0, right = n - 1, key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    while (left <= right) {
        int mid = left + (right - left) / 2; // Fixed missing semicolon

        if (arr[mid] == key) {
            printf("Key found at index %d\n", mid);
            return 0;
        } else if (arr[mid] < key) {
            left = mid + 1; // Fixed incorrect assignment
        } else {
            right = mid - 1;
        }
    }

    printf("Key not found\n");
    return 0;
}