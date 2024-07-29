// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x){
        data=x;
        next=nullptr;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> mp;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(mp[temp]){
                return temp;
            }
            mp[temp]=true;
            temp=temp->next;
        }
        return nullptr;
    }
};

//optimal approach 
ListNode* detect(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
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

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = s.detectCycle(head);
    cout << head->data;
    return 0;
}