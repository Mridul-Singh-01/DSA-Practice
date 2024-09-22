#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

tuple<vector<int>, vector<int>, vector<int>> allTraversal(Node* root) {
    vector<int> pre, in, post;
    stack<pair<Node*, int>> st;
    st.push({root, 1});

    if (root == nullptr) 
        return {pre, in, post};

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != nullptr) {
                st.push({it.first->left, 1});
            }
        } 
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != nullptr) {
                st.push({it.first->right, 1});
            }
        } 
        else {
            post.push_back(it.first->data);
        }
    }
    return {pre, in, post};
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    auto [pre, in, post] = allTraversal(root);
    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << "\nInorder: ";
    for (int x : in) cout << x << " ";
    cout << "\nPostorder: ";
    for (int x : post) cout << x << " ";
    return 0;
}
