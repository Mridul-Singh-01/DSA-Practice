#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1,nullptr);
        ListNode* temp=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1!=nullptr){
            temp->next=list1;
        }
        if(list2!=nullptr){
            temp->next=list2;
        }
        return dummy->next;
    }
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    vector<int> list1 = {1, 2, 4};
    vector<int> list2 = {1, 3, 4};
    ListNode* l1 = createList(list1);
    ListNode* l2 = createList(list2);
    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(l1, l2);
    cout << "Merged list: ";
    printList(mergedList);
    return 0;
}