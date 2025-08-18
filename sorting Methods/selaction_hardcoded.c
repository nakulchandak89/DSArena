#include<stdio.h>

int main(){
    int i,j,temp,minindex;
    int arr[10] = { 25,100,10,5,27,85,40,58,20,36};

    printf("Sorting has started hear");
    for(i=0; i<10; i++){
        minindex = i;

        for(j= i+1; j<10; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }

    printf("this is the sorted Array: ");
    for(i=0;i<10;i++){
        printf("%d, \t", arr[i]);
    }

    return 0;
}