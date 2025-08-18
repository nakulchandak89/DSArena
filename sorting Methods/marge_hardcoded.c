#include<stdio.h>

void marge(int arr[], left, mid, right){
    int n1, n2;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i=0;i<m1;i++){
        L[i] = arr[left + i ];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[mid + 1 + j];
    }

    int i=0,j=0,k= left;
    while(i<n1&&j<n2){
        if(L[i] <R[j]){
            arr[k] = L[i];
            i++;
        }else{
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

void mergesort(int arr[], left, right){
    while(left < right){
        int mid = left + (right  - right) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}