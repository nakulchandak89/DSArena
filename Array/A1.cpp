// Write a C++ program to find the largest element of a given array of integers

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {2, 5, 9, 7, 6, 4, 1, 3, 8};
    int even[9]; // Array to store even numbers
    int evenCount = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    // Separate even numbers
    for(int i = 0; i < 9; i++) {
        if(arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        }
    }
    

    // Print even numbers
    cout << "Even numbers: ";
    for(int i = 0; i < evenCount; i++) {
        cout << even[i] << " ";
    }
    cout << endl;
sort(arr, arr + n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<"\t";
}
    return 0;
}

// Write a C++ program to separate even and odd numbers in an array of integers. Put all even numbers first, and then odd numbers.
