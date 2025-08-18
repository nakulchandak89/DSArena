#include<stdio.h>
// this script holds Interpolation search 
int main(){
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }   
    
int key;
// we can consider this pos as mid 
printf("Enter the key: ");
scanf("%d", &key);

int left=0,right=n-1;
int pos;

while(left<=right && key >= arr[left] && key<=arr[right]){
    pos = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
    
    // printf("trying postion %d: arr[%d] = %d\n", pos, pos, arr[pos]);
    
    if(arr[pos] == key){
        printf("we get the element on %d index", pos);
        return 0;
    }
    if(arr[pos] < key){
        left = pos + 1;
    }
    else{
        right = pos - 1;
    }
    
}
    return 0;
}