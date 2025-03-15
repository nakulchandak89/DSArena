// this is the bubble sort
#include<stdio.h>

int main(){
    
    int n;
// take the input from user 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
// stores the elements in the user define array 
    for(int i=0;i<n;i++){
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int temp;
// bubble sort algo
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(arr[j] > arr[j + 1]){ // this is responsable for the position of the sorted array 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // printing array
    printf("Sorted aray: ");
    for(int i=0; i<n; i++){
        printf("%d \t", arr[i]);
    }
    
    return 0;

}