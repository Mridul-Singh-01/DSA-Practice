//LEETCODE PROBLEM 206
// Given the head of a singly linked list, reverse the list, and return the reversed list.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *front = nullptr;
        ListNode *prev = nullptr;
        while (temp != nullptr)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
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

//using recusion
ListNode* reverse(ListNode* head){
    if(head==nullptr || head->next==nullptr)return head;
    ListNode* newHead=reverse(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
}

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = s.reverseList(head);
    s.printLL(head);
    return 0;
}