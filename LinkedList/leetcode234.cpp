// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* front=nullptr;
        while(temp!=nullptr){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {     //time complexity O(n) and space complexity O(1)
        if(head==nullptr || head->next==nullptr)return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverse(slow);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=nullptr){
            if(second->val!=first->val){
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newHead);
        return true;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    Solution s;
    cout << s.isPalindrome(head);
    return 0;
}