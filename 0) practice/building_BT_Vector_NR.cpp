//TODO - drafting the script which will take the input from Vector and build tree non recursivly 
#include<iostream>
#include<vector>
#define max_size 100
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

class stack{
    public:
        node* arr[max_size];
        int top;
    stack(){
        top = -1;
    }
    bool is_empty(){return top == -1;}
    bool is_full(){return top == max_size - 1;}
    void push(node* address){
        if(is_full()){
            return;
        }
        arr[++top] = address;
    }
    void pop(){
        if(is_empty()){
            return;
        }
        top--;
    }
    node* peek(){
        if(is_empty()){
            return nullptr;
        }
        return arr[top];
    }
};

node* Build_tree(const vector<int>& preorder){
    if (preorder.empty() || preorder[0] == -1) {
        return nullptr;
    }

    int idx = 0;
    node* root = new node(preorder[idx++]);
    stack s;
    s.push(root);

    while (!s.is_empty()) {
        node* current = s.peek();
        s.pop();

        // --- Process the left child ---
        if (idx < preorder.size() && preorder[idx] != -1) {
            current->left = new node(preorder[idx]);
        }
        idx++;

        // --- Process the right child ---
        if (idx < preorder.size() && preorder[idx] != -1) {
            current->right = new node(preorder[idx]);
        }
        idx++;

        // Push the children onto the stack for the next iteration.
        // We push the right child first, so the left child is processed first (LIFO).
        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
    return root;
}

// Helper function to print the tree and verify its structure
void inorder_traversal(node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    stack s;
    node* current = root;

    cout << "Inorder Traversal: ";
    while (current != nullptr || !s.is_empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.peek();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, -1};
    
    cout << "Building tree from vector..." << endl;
    node* root = Build_tree(preorder);
    inorder_traversal(root);

    return 0;
}
