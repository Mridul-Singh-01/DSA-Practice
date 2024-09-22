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

class Solution {
public:
    bool isSameTree(Node* p, Node* q) {
        if(p==nullptr && q==nullptr){
            return true;
        }
        if(p==nullptr || q==nullptr){
            return false;
        }
        if(p->data!=q->data){
            return false;
        }
        bool a=isSameTree(p->left,q->left);
        bool b=isSameTree(p->right,q->right);
        return a&&b;
    }
};