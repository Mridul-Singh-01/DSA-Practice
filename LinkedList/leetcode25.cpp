#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* findKthListNode(ListNode* temp, int k) {
        k = k - 1;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* front = nullptr;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    struct ListNode *reverseIt(struct ListNode *head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }
        ListNode* temp = head;
        ListNode* newHead = nullptr;
        ListNode* prevListNode = nullptr;
        while (temp != nullptr) {
            ListNode* kthListNode = findKthListNode(temp, k);
            if (kthListNode == nullptr) {
                ListNode* reversedSegment = reverseList(temp);
                if (prevListNode != nullptr) {
                    prevListNode->next = reversedSegment;
                }
                break;
            }
            ListNode* nextSegment = kthListNode->next;
            kthListNode->next = nullptr;
            ListNode* reversedSegment = reverseList(temp);
            if (newHead == nullptr) {
                newHead = reversedSegment;
            } else {
                prevListNode->next = reversedSegment;
            }
            prevListNode = temp;
            prevListNode->next = nextSegment;
            temp = nextSegment;
        }
        return newHead;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(6);
    cout << "Original list: ";
    printList(head);
    int k = 3;
    Solution sol;
    head = sol.reverseIt(head, k);
    cout << "Reversed list: ";
    printList(head);
    return 0;
}