//TODO - conversion in between postfix to infix
#include <iostream>
#include <string>
#include<algorithm>
#define max_size 100
using namespace std;

class stack{
private:
    char arr[max_size];
    int top;
public:
    stack(){
        top = -1;
    }
    bool is_full(){return top == max_size - 1;}
    bool is_empty(){return top == -1;}
    void push(char ch){
        if(is_full()){
            cerr<<"stack overflowed"<<endl;
            return;
        }
        arr[++top] = ch;
    }
    void pop(){
        if(is_empty()){
            cerr<<"stack is empty"<<endl;
            return;
        }
       --top;
    }
    char peek(){
        if(is_empty()){
            cerr<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};

int getprecedance(char c){
        if(c == '^'){
        return 3;
    }else if(c == '*' || c == '/'){
        return 2;
    }else if(c == '+' || c == '-'){
        return 1;
    }else{
        return -1;
    }
}

string infix_postfix(string s){
    stack st;
    string result = "";
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(isalpha(c) || isdigit(c)){
            result += c;
        }else if(c == '('){
            st.push('(');
        }else if(c == ')'){
            while(!st.is_empty() && st.peek() != '('){
                result += st.peek();
                st.pop();
            }
            if(!st.is_empty()){
                st.pop();
            }
        }else{
            while(!st.is_empty() && getprecedance(c) <= getprecedance(st.peek())){
                result += st.peek();
                st.pop();
            }
            st.push(c);
        }
        
    }
    while(!st.is_empty()){
        result += st.peek();
        st.pop();
    }
    return result;
}

string infix_prefix(string infix){
    reverse(infix.begin(), infix.end());
    for(int i=0;i<infix.length();i++){
         if(infix[i]=='('){
            infix[i] = ')';
        }else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }
    string prefix = "";
    stack st;
    for(int i=0;i<infix.length(); i++){
        char c = infix[i];
        if(isalpha(c) || isdigit(c)){
            prefix += c;
        }else if(c == '('){
            st.push('(');
        }else if(c == ')'){
            while(!st.is_empty() && st.peek() != '('){
                prefix += st.peek();
                st.pop();
            }
            if(!st.is_empty()){
                st.pop();
            }
        }else{
            while(!st.is_empty() && getprecedance(c) < getprecedance(st.peek())){
                prefix += st.peek();
                st.pop();
            }
            st.push(c);
        }
        while(!st.is_empty()){
            st.pop();
        }
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix_expr = "a+b*(c/d)";
    string postfix_expr = infix_postfix(infix_expr);

    cout << "--- Infix to Postfix Conversion ---" << endl;
    cout << "Infix expression: " << infix_expr << endl;
    cout << "Postfix expression: " << postfix_expr << endl;

    string infix_expr2 = "x+y*z/w+u";
    cout << "\n--- Infix to Prefix Conversion ---" << endl;
    cout << "Infix expression: " << infix_expr2 << endl;
    cout << "Prefix expression: " << infix_prefix(infix_expr2) << endl;
    return 0;
}
