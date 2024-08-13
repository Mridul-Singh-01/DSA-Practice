// Delete all occurrences of a given key in a doubly linked list - > GFG
// You are given the head_ref of a doubly Linked List and a Key.
// Your task is to delete all occurrences of the given key if it is present and return the new DLL.

#include <bits/stdc++.h>
using namespace std;

void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    // Write your code here
    Node *temp = *head_ref;
    while (temp != nullptr)
    {
        if (temp->data == x)
        {
            Node *toDelete = temp;
            if (temp == *head_ref)
            {
                *head_ref = temp->next;
                if (*head_ref != nullptr)
                {
                    (*head_ref)->prev = nullptr;
                }
            }
            else
            {
                if (temp->prev != nullptr)
                {
                    temp->prev->next = temp->next;
                }
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }
            }
            free(toDelete);
        }
        temp = temp->next;
    }
}

int main()
{
    
    return 0;
}