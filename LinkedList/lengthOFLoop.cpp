#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* detect(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while (slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* temp=detect(head);
    if(temp!=nullptr){
        int c=1;
        Node* it=temp->next;
        while(it!=temp){
            c++;
            it=it->next;
        }
        return c;
    }
    return 0;
}