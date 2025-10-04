//TODO - implimenting an stack for geting fibunacci series and factorial of an number
//REVIEW - This is an Menu driven program for printing an fibbunacci series and factorial of an number
#include<iostream>
#define max_size 100
using namespace std;

class stack{
private:
    int arr[max_size];
    int top;
public:
    stack(){
        top = -1;
    }
    bool is_empty(){return top == -1;}
    bool is_full(){return top == max_size - 1;}
    void push(int val){
        if(is_full()){
            cerr<<"Stack is overfloded"<<endl;
            return;
        }
        arr[top++] = val;
        cout<<val<<"is added to stack"<<endl;
    }
    int pop(){
        if(is_empty()){
            cerr<<"Stack is empty"<<endl;
            return -1;
        }
        int pop_ed = arr[--top];
       return pop_ed;
    }
    int peek(){
        if(is_empty()){
            cerr<<"No peek value as such"<<endl;
            return -1;
        }
        return arr[top];
    }
    int display(){
        if(is_empty()){
            cerr<<"No value to display!!"<<endl;
            return -1;
        }
        for(int i=0;i<top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int get_factorial(int num){
    stack st;
    for(int i=num;i>=1;i--){
        st.push(i);
    }
    long long factorial = 1;
    while(! st.is_empty()){
        factorial *= st.pop();
    }
    cout<<"Factorial of "<<num<<" is "<<factorial<<endl;
}

int get_fibunacci(int num){
    stack st2;
    if(num <= 0){
        cerr<<"Enter the possitinve value"<<endl;
        return -1;
    }
    if(num >= 1){
        cout<<"0 ";
        st2.push(0);
    }
    if(num >= 2){
        cout<<"1 ";
        st2.push(1);
    }
    for(int i=3;i<=num;i++){
        int first = st2.pop();
        int second = st2.peek();

        int next = first + second;
        cout<<next<<" ";

        st2.push(first);
        st2.push(next);
    }
}

int main(){
    int num, input;

    cout<<"Enter what you want to perform on the stack\n"<<"1) get Factorial\n"<<"2) get Fibunacci serious"<<endl;
    cout<<"Enter hear: ";
    cin>>input;

    if(input == 1){
        cout<<"Enter the number to get it's factorial: ";
        cin>> num;
        get_factorial(num);
    }else if(input == 2){
        cout<<"Enter the number to get it's fibunnaci number: ";
        cin>>num;
        get_fibunacci(num);
    }else{
        cerr<<"Enter the value correctly"<<endl;
        return -1;
    }

    return 0;
}