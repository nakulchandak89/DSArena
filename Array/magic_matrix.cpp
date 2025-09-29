
// this script is for printing the odd magic matrix
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; 
    cout << "Enter the order of the matrix: ";
    cin >> n;

    // Declare a 2D vector
    vector<vector<int>> arr(n, vector<int>(n, 0));

    int num = 1;

    int i = 0, j = n/2;
    while(num <= n*n){
        arr[i][j] = num;
        num ++;
    
    int s = (i - 1 + n) % n;
    int l = (j + 1) % n;

    if(arr[s][l] != 0){
        i = (i + 1) % n;
    } else{
        i = s;
        j = l;
     }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    // Additional code to fill the magic matrix can be added here

    return 0;
}