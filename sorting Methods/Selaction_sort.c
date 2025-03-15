// this is the selaction sort
#include<stdio.h>

int main(){
    int n, j, i;
    int temp;
    int minIndex;
    printf("Enetr the how many elements are present in the arrya: ");
    scanf("%d", &n);

    int arr[n];
    for(i = 0;i<n; i++){
        printf("Enter the element number: %d: ", i);
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++){
        // Assume the element at index i is the smallest
        minIndex = i;
        
        // Search for the smallest element in the unsorted part
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;  // Update minIndex if a smaller element is found
            }
        }
        
        // Swap the found smallest element with the element at index i
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    
    printf("Thsi is the sorted array: ");
    for(int i = 0; i<n; i++){
        printf(" %d", arr[i]);
    }

    return 0;
}