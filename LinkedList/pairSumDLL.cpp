// GFG - > Find pairs with given sum in doubly linked list
// Given a sorted doubly linked list of positive distinct elements,
// the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);
    Node *last = *head_ref;

    if (*head_ref == nullptr)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // code here
    vector<pair<int, int>> ans;
    Node *temp1 = head;
    Node *temp2 = head;
    while (temp2->next != nullptr)
    {
        temp2 = temp2->next;
    }
    while (temp1 != nullptr && temp2 != nullptr && temp1 != temp2 && temp1->prev != temp2)
    {
        int sum = temp1->data + temp2->data;
        if (sum == target)
        {
            ans.push_back({temp1->data, temp2->data});
            temp1 = temp1->next;
            temp2 = temp2->prev;
        }
        else if (sum < target)
        {
            temp1 = temp1->next;
        }
        else
        {
            temp2 = temp2->prev;
        }
    }
    return ans;
}

int main()
{
    Node *head = nullptr;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    int target = 5;
    vector<pair<int, int>> result = findPairsWithGivenSum(head, target);
    for (auto &p : result)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    return 0;
}