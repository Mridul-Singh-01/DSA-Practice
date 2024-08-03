#include <iostream>
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {       //Time Complexity O(nlogk) and space complexity O(n)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();            
            if (it.second->next) {
                pq.push({it.second->next->val, it.second->next});
            }
            temp->next = it.second;
            temp = temp->next;
        }
        return dummy->next;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* createList(vector<int> nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<vector<int>> listVectors = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists;
    for (auto vec : listVectors) {
        lists.push_back(createList(vec));
    }
    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);
    cout << "Merged list: ";
    printList(mergedList);
    return 0;
}
