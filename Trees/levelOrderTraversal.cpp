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

vector<vector<int>> levelOrder(Node* head){
    vector<vector<int>> res;
    if(head==nullptr)return res;
    queue<Node*> q;
    q.push(head);
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
        res.push_back(level);
    }
    return res;
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);
    cout << "Level Order : ";
    vector<vector<int>> ans=levelOrder(head);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}
//Another Apporach 
// int height(struct node* node){
//     if(node==NULL){
//         return 0;
//     }
//     int lheight=height(node->left);
//     int rheight=height(node->right);
//     if(lheight>rheight){
//         return lheight+1;
//     }
//     else{
//         return rheight+1;
//     }
// }

// void printCurrentLevel(struct node* node,int level){
//     if(node==NULL){
//         return;
//     }
//     if(level==1){
//         printf("%d  ",node->data);
//     }
//     else if(level>1){
//         printCurrentLevel(node->left,level-1);
//         printCurrentLevel(node->right,level-1);
//     }
// }


// void printLevel(struct node* node){
//     for(int i=1;i<=height(node);i++){
//         printCurrentLevel(node,i);
//     }
// }
