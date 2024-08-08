// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* curr=dummyNode;
        int carry=0;
        while(temp1!=nullptr || temp2!=nullptr){
            int sum=carry;
            if(temp1){
                sum+=temp1->val;
                temp1 = temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2 = temp2->next;
            }
            ListNode* NewNode=new ListNode(sum%10);
            carry=sum/10;
            curr->next=NewNode;
            curr=curr->next;
        }
        if(carry){
            ListNode* NewNode=new ListNode(carry);
            curr->next=NewNode;
        }
        return dummyNode->next;
    }
};

ListNode* createList(std::vector<int> nums) {
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val;
        if (curr->next != nullptr) {
            std::cout << " -> ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main(){
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4};
    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);
    cout << "First List: ";
    printList(l1);
    cout << "Second List: ";
    printList(l2);
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    cout << "Result List: ";
    printList(result);
    return 0;
}