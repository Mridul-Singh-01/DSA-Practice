#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};

Node* constructLL(vector<int>& arr) {
    Node* head=new Node(arr[0]);
    Node* it=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        it->next=temp;
        it=temp;
    }
    return head;
}

void printLL(Node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
    cout << "\n";
}

Node* deleteHead(Node* head){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* it=head;
    while(it->next->next!=NULL){
        it=it->next;
    }
    free(it->next);
    it->next=NULL;
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int c=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
        c++;
        if(c==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeVal(Node* head,int val){
    if(head==NULL) return head;
    if(head->data==val){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
        if(temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={20,30,40,50,60};
    Node* head=constructLL(arr);
    printLL(head);
    head=removeKthElement(head,5);
    printLL(head);
    return 0;
}