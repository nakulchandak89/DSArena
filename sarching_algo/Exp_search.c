#include<stdio.h>

// this script holds the Expontioal search algo 

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Correct typo in scanf

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d element: ", i + 1); // Fix missing argument in printf
        scanf("%d", &arr[i]);
    }

    // search algo 
    int key, left = 0, right, bound = 1;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Find the range for binary search
    while (bound < n && arr[bound] < key) { 
        left = bound;
        bound *= 2;
    }
    right = (bound < n) ? bound : n - 1;

    // Perform binary search in the found range
    int found = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}