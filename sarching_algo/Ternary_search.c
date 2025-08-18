#include<stdio.h>
// ternary search algo 
// for sorted data we have marge sort algo and after that ternary search algo

// main marge sort logic
void marge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for(int i=0;i<n1;i++){
        L[i] = arr[left + i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[mid + j + 1];
    }
    
    int i=0,j=0,k=left;
    
    while(i<n1&&j<n2){
        if(L[i]<R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

// recurrcation 
void margesort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right - left) / 2;
        
        margesort(arr, left, mid);
        margesort(arr, mid+1, right);
        
        marge(arr, left, mid, right);
    }
}

void printarr(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// main function
int main(){ 
    int n;
    
    printf("Enter the number of element: ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter %d element: ", i);
        scanf("%d", &arr[i]);
    }
    
    
    margesort(arr, 0 , n-1);
    printarr(arr, n);
    
	//ternary search algo
    int left=0,right=n-1,key;
    int found = 0;
    
    printf("enter the element to be search: ");
    scanf("%d", &key);
    
    while (left <= right) { 
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3; 

        if (arr[mid1] == key) {
            printf("element found on index %d\n", mid1);
            found = 1;
            break;
        }
        if (arr[mid2] == key) {
            printf("element found on index %d\n", mid2);
            found = 1;
            break;
        }

        if (key < arr[mid1]) {
            right = mid1 - 1;
        } else if (key > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return 0;
}