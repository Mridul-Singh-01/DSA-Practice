#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* cycleNode = head;
    for (int i = 0; i < pos; i++) {
        cycleNode = cycleNode->next;
    }
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = cycleNode;
}

int main() {
    Solution solution;
    int arr1[] = {3, 2, 0, -4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createList(arr1, n1);
    createCycle(head1, 1);
    cout << (solution.hasCycle(head1) ? "Cycle detected" : "No cycle detected") << endl;
    return 0;
}
