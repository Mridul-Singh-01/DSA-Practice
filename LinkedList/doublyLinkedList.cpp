#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;
    Node(int x){
        data=x;
        next=nullptr;
        back=nullptr;
    }
    Node(int x,Node* next1,Node* back1){
        data=x;
        next=next1;
        back=back1;
    }
};

void printLL(Node* head){
    while(head!=nullptr){
        cout << head->data << " ";
        head=head->next;
    }
}

Node* convertArrayToDL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;  //or prev=prev->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArrayToDL(arr);
    printLL(head);
    return 0;
}