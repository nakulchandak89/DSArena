// Merge Sort Algo

#include<stdio.h>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i] = arr[left + i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[mid + j + 1];
    }

    int i=0,j=0,k= left;
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
        arr[k]=R[j];
        j++;
        k++;
    }
}

void sort_merge(int arr[], int left, int right){
    if (left < right){
        int mid = left + (right-left)/2;

        sort_merge(arr, left, mid);
        sort_merge(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void printarr(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
int arr[8]; 
int size = 7;

printf("Enter your array: ");
for(int i=0; i<7; i++){
    scanf("%d", &arr[i]);
}

printf("You had enter this array and this is an orignal array\n");
printarr(arr, size);

sort_merge(arr, 0, size-1);

printf("now this is an sorted array by the method of mearge sort:\n");
    
printarr(arr, size);

return 0;
}
