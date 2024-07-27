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
    cout << "\n";
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

Node* insertAtHead(Node* head, int val){
    Node* temp=new Node(val,head,nullptr);
    head->back=temp;
    return temp;
}

Node* insertAtEnd(Node* head,int val){
    if(head==NULL) return head;
    Node* it=head;
    while(it->next!=nullptr){
        it=it->next;
    }
    Node* temp=new Node(val,nullptr,it);
    it->next=temp;
    return head;
}

Node* insertAtK(Node* head,int val,int k){
    if(head==nullptr){
        if(k==1){
            Node* temp=new Node(val);
            return temp;
        }
    }
    if(k==1){
        Node* temp=new Node(val,head,nullptr);
        head->back=temp;
        return temp;
    }
    int c=0;
    Node* it=head;
    while(it!=nullptr){
        c++;
        if(c==k-1){
            Node* temp= new Node(val,it->next,it);
            it->next=temp;
            if(temp->next!=nullptr){
                temp->next->back=temp;
            }
            break;
        }
        it=it->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4};
    Node* head=convertArrayToDL(arr);
    printLL(head);
    head=insertAtEnd(head,9);
    printLL(head);
    return 0;
}