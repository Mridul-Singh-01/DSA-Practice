// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

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
    ListNode* oddEvenList(ListNode* head) {     //time complexity O(n) and space complexity O(1)
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next;
        while(even!=nullptr && even->next!=nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next=evenHead;
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
    ListNode* temp=s.oddEvenList(head);
    s.printLL(temp);
    return 0;
}