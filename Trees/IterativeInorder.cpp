#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> inOrder(Node* root) {
    vector<int> res;
    stack<Node*> st;
    Node* temp = root;
    while(true){
        if(temp!=nullptr){
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()) break;
            temp=st.top();
            st.pop();
            res.push_back(temp->data);
            temp=temp->right;
        }
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = inOrder(root);
    cout << "In-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
