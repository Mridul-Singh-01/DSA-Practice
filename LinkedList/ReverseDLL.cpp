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

//brute force solution
// Node* reverseDLL(Node* head){      //time complexity O(n) and space complexity O(n)
//     if(head==nullptr)return head;
//     stack<int>st;
//     Node* it=head;
//     while(it!=nullptr){
//         st.push(it->data);
//         it=it->next;
//     }
//     it=head;
//     while(it!=nullptr){
//         it->data=st.top();
//         st.pop();
//         it=it->next;
//     }
//     return head;
// }

Node* reverseDLL(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* current=head;
    Node* last=nullptr;
    while(current!=NULL){       //time complexity O(n) and space complexity O(1)
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    return last->back;
}

int main(){
    vector<int> arr={1,2,3,4};
    Node* head=convertArrayToDL(arr);
    printLL(head);
    head=reverseDLL(head);
    printLL(head);
    return 0;
}