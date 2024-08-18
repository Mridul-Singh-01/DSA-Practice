#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode *next;

    QueueNode(int a) {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

void MyQueue:: push(int x)
{
    QueueNode* newNode = new QueueNode(x);
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}

int MyQueue :: pop()
{   if (front == nullptr) {
        return -1;
    }
    int poped=front->data;
    QueueNode* temp=front;
    front=front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return poped;
}

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(40);
    q.push(50);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}
