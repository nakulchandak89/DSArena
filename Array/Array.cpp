// this is the Question set of the array and basic logic building 
#include<iostream>
#include<algorithm>
using namespace std;

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

int main(){
 int opt;

 cout<<"Enter the Question for Which you want solution: "<<endl;

 switch (opt){
    case 1:
        Q1();
        break;
    case 2:
        Q2();
        break;
    case 3:
        Q3();
        break;
    case 4:
        Q4();
        break;
    case 5:
        Q5();
        break;
    
 }

    return 0;
}

void Q1(){
int arr[] = {2, 8, 7, 3, 6};
int max = arr[0];
cout<<"greatest Element in this array is: ";
cout<<endl;
for(int i=0;i<5;i++){
     cout<<arr[i] << endl;
}
for(int i=0;i<5;i++){
    if(arr[i]>max){ // this is the core logic and hear we are compariing the index 
        max = arr[i];
    }
}
cout<<"This is the greatest element: "<<max<<endl;
}

void Q2(){
    cout<<"Write a C++ program to find the largest threeed and lowest threed elements in an array."<<endl;

        int arr[] = {2, 8, 9, 6, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Sort the array
  sort(arr, arr + n);
    
 for(int i=0;i<n;i++){
    cout<<arr[i]<<"\t";
 }
 cout<<endl;
 cout<<"the 3rd smallest number in the array is: "<<arr[2]<<endl;
 cout<<"the 3rd greatest number in the array is: "<<arr[n-3];


}

void Q3(){
    cout<<" Write a C++ program to find the most frequent element in an array of integers."<<endl;
        int arr[] = {2, 8, 9, 6, 4, 3, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_count = 0;
// this loop os to start the array from the index 1
  for(int i=0;i<n;i++){
    int count = 1; // for every number we are setinh the by default coumt 1 
    for(int j=i+1;j<n;j++){ //now this array starts with the index 2 as we had checkeed the number from index 1
        if(arr[i] == arr[j]){ // this is the condition to check wether the number is same or not 
            count++; // if we find the number same we will just increase the count
        }        
    if(max_count < count){ // this is the extra step as if wwe get the count greather than zero 
     max_count = count; // then we update the count to the new variable
     cout<<arr[i]<<"\t";  // this is going to print the number which is repartative 
      }
    }
  }

cout<<" we get this number as "<<max_count<<" times in our array"<<endl; //this is teh final printing statement

}

void Q4(){
    cout<<"this is the patern shocaasing the conditional statement"<<endl;
    int arr[5][5];

for(int i=0;i<=5;i++){
    for(int j=0;j<=5;j++){
        // by this we access both the digonal elements
        if(i == j || i == 5-j){
            cout<<"- \t";
        }
        //this statement is for geting both side 4 - 4 elements to convert
        else if(0<i<5 && j == 5 || 0<i<5 && j == 0){
            cout<<"+ \t";
        }
        //this is for the accessing the top 4 element 
        else if(i==5 && 0<j<5 || i==0 && 0<j<5 ){
            cout<<"| \t";
        }
        else{
            cout<<i<<j<<"\t";
        }   
    }
    cout<<endl;
}
}
//Write a C++ program to separate even and odd numbers in an array of integers. Put all even numbers first, and then odd numbers.
void Q5(){
    
}