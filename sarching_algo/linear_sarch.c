#include<stdio.h>
// linear search
int main(){
    // size of array
    int n;
    printf("Enter the number of the elements present in the Array: ");
    scanf("%d", &n);
    // taking input of the array
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
    // take the Key input from user
    int key;
    printf("Enter the value want to sarch in the array: ");
    scanf("%d", &key);
    //linear search algo
    for(int i=0;i<n;i++){
        if(arr[i]==key){
         printf("we get the key entered by you at index: %d ", i);
         return i;
        }
    }
    return 0;
}

// lenar search algo is basically chaks every element 