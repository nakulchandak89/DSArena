// #include<stdio.h>
// // in this script we have an fibonacci search algo 
// void mergesort (int arr[], int left, int mid, int right){
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     int L[n1],R[n2];

//     for(int i=0;i<n1;i++){
//         L[i] = arr[left + 1];
//         i++;
//     }
//     for(int j=0;j<n2;j++){
//         R[j] = arr[mid + j + 1];\
//         j++;
//     }
//     int i = 0,j=0,k =left;
//     while(i<n1&&j<n2){
//         if(L[i]<R[j]){
//             arr[k] = L[i];
//             i++;
//         }
//         else{
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
//     while
// }
// int main(){

//     return 0;
// }

#include <stdio.h>

// Fibonacci Search function
int fibonacciSearch(int arr[], int n, int key) {
    int fib2 = 0;      // (m-2)'th Fibonacci No.
    int fib1 = 1;      // (m-1)'th Fibonacci No.
    int fib = fib1 + fib2; // m'th Fibonacci No.

    // fib is going to store the smallest Fibonacci Number >= n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        // Check if fib2 is a valid location
        int i = (offset + fib2 < n) ? offset + fib2 : n - 1;

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i; // Element found
        }
    }

    // Comparing the last element with key
    if (fib1 && arr[offset + 1] == key)
        return offset + 1;

    return -1; // Element not found
}

int main() {
    int arr[] = {3, 5, 8, 10, 14, 17, 20, 23, 27, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = fibonacciSearch(arr, n, key);

    if (result >= 0)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
