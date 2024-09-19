#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        if(node==nullptr)return ans;
        stack<Node*> s;
        s.push(node);
        while(!s.empty()){
            Node* temp=s.top();
            s.pop();
            if(temp->left)s.push(temp->left);
            if(temp->right)s.push(temp->right);
            ans.push_back(temp->data);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};