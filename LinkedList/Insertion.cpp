#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x,Node* temp){
        data=x;
        next=temp;
    }
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printLL(Node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
    cout << "\n";
}

Node* insertAtHead(Node* head, int val){
    Node* temp=new Node(val);
    temp->next=head;
    return temp;
}


Node *insertAtEnd(Node *head, int x) {
        Node* temp = new Node(x);
        if(head==nullptr){
            return temp;
        }
        Node* it=head;
        while(it->next!=nullptr){
            it=it->next;
        }
        it->next=temp;
        return head;
}

Node* insertAtPostition(Node* head, int val, int k){
    if(head==NULL){
        if(k==1){
            Node* temp=new Node(val,head);
            return temp;
        }
    }
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    Node* it=head;
    Node* prev=NULL;
    int c=0;
    while (it!=nullptr){
        c++;
        if(c==k-1){
            Node* temp=new Node(val);
            temp->next=it->next;
            it->next=temp;
            break;
        }
        it=it->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int val,int valAt){
    if(head==NULL){
        return head;
    }
    if(head->data==valAt){
        Node* temp=new Node(val);
        temp->next=head;
        return temp;
    }
    Node* it=head;
    while(it!=nullptr){
        if(it->next->data==valAt){
            Node* temp=new Node(val);
            temp->next=it->next;
            it->next=temp;
            break;
        }
        it=it->next;
    }
    return head;
}

int main(){
    Node* head=NULL;
    head=insertAtHead(head,20);
    printLL(head);
    head=insertAtEnd(head,30);
    head=insertAtHead(head,10);
    printLL(head);
    head=insertAtPostition(head,40,4);
    printLL(head);
    head=insertBeforeValue(head,70,40);
    printLL(head);
    return 0;
}