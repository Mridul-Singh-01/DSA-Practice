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

Node* deleteHead(Node* head){
    if(head==nullptr || head->next==nullptr){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    free(prev);
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return NULL;
    }
    Node* it=head;
    while(it->next!=nullptr){
        it=it->next;
    }
    Node* prev=it->back;
    prev->next=nullptr;
    it->back=nullptr;
    free(it);
    return head;
}

Node* deleteKthElement(Node* head,int k){
    if(head==nullptr || head->next==nullptr){
        return NULL;
    }
    if(k==1){
        Node* prev=head;
        head=head->next;
        head->back=nullptr;
        prev->next=nullptr;
        free(prev);
        return head;
    }
    int c=0;
    Node* it=head;
    while(it!=nullptr){
        c++;
        if(c==k){
            Node* prev=it->back;
            prev->next=it->next;
            if(it->next!=nullptr){
                it->next->back=it->back;
            }
            it->next=nullptr;
            it->back=nullptr;
            free(it);
            break;
        }
        it=it->next;
    }
    return head;
}

Node* deleteBeforeVal(Node* head, int val){
    if(head==nullptr || head->next==nullptr){
        return NULL;
    }
    if(head->data==val){
        Node* prev=head;
        head=head->next;
        head->back=nullptr;
        prev->next=nullptr;
        free(prev);
        return head;
    }
    Node* it=head;
    while(it!=nullptr){
        if(it->data==val){
            Node* prev=it->back;
            prev->next=it->next;
            if(it->next!=nullptr){
                it->next->back=it->back;
            }
            it->next=nullptr;
            it->back=nullptr;
            free(it);
            break;
        }
        it=it->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArrayToDL(arr);
    printLL(head);
    head=deleteBeforeVal(head,1);
    printLL(head);
    return 0;
}