

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)return head;
        if(head->next==nullptr && n==1)return nullptr;
        int count=0;
        ListNode* it=head;
        while(it!=nullptr){
            count++;
            it=it->next;
        }
        int index=count-n;
        if(index==0){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        it=head;
        int c=0;
        while(it!=nullptr){
            c++;
            if(c==index){
                ListNode* temp=it->next;
                it->next=it->next->next;
                delete temp;
                break;
            }
            it=it->next;
        }
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
    ListNode* temp=s.removeNthFromEnd(head,3);
    s.printLL(temp);
    return 0;
}