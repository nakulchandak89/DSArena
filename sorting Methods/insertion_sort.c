// this is the insertion sort
#include<stdio.h>
int main(){
 int n, key, j;
// this is the input part
printf("Enter the number of the elements: ");
scanf("%d", &n);
int arr[n];
for(int i=0;i<n;i++){
    printf("Enter the number of element %d ", i);
    scanf("%d", &arr[i]);
}

// Insertion sort algorithm
    // Start from the second element (index 1) because the first element is considered sorted.
for(int i=1;i<n;i++){
    key = arr[i]; // The element to be inserted into the sorted part
    j = i - 1;     // Start comparing with the element immediately to the left

    // Move elements of the sorted segment that are greater than key one position ahead
    while(j>= 0 && arr[j] > key){
        arr[j + 1] = arr[j];
        j--; 
    }
    // Insert the key element into its correct position
    arr[j + 1] = key;
}
// this is printing part
printf("this is the sorted array: ");
for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
}

return 0;
}