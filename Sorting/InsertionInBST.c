#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* NewNode(int data){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

struct node* insert(struct node* node, int data){
    if(node==NULL){
        return NewNode(data);
    }
    if(node->data > data){
        node->left=insert(node->left,data);
    }
    else if(node->data < data){
        node->right=insert(node->right,data);
    }
    return node;
}

void display(struct node* node){
    if(node!=NULL){
        display(node->left);
        printf("%d  ",node->data);
        display(node->right);
    }
}

struct node* searching(struct node* root,int data){
    if(root==NULL || root->data==data){
        return root;
    }
    else if(root->data>data){
        return searching(root->left,data);
    }
    else{
        return searching(root->right,data);
    }
}

int main(){
    struct node* root=NULL;
    root=insert(root,50);
    insert(root,60);
    insert(root,30);
    display(root);
    if(searching(root,40)==NULL){
        printf("Not Found");
    }
    else{
        printf("Found");
    }
    return 0;
}