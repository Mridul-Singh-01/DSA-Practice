// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing,

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        int c=0;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
    }
    void printLL(ListNode *head)
    {
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "\n";
    }
};

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    s.printLL(head);
    ListNode* temp=s.deleteMiddle(head);
    s.printLL(temp);
    return 0;
}