//ZigZag Travsal means like level order traversal but first to left to right then right to left and alternate every time

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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==nullptr)return res;
        queue<Node*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            vector<int> level;
            int s=q.size();
            for(int i=0;i<s;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                level.push_back(temp->data);
            }
            if(flag%2==1){
                reverse(level.begin(),level.end());
            }
            res.push_back(level);
            flag++;
        }
        return res;
    }
};