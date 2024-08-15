#include <bits/stdc++.h>
using namespace std;

class stImpl {
    int start = 0;
    int end = -1;
    int currSize = 0;
    int arr[10000];
    int maxSize = 10000;

public:
    void push(int data) {
        if (currSize >= maxSize) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = data;
        cout << "The element pushed is " << data << endl;
        currSize++;
    }

    int pop() {
        if (currSize == 0) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int popped = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }

    int size() {
        return currSize;
    }

    int top() {
        if (currSize == 0) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[start];
    }
};

int main() {
    stImpl s;
    s.push(1);
    s.push(2);
    s.pop();
    cout << s.top() << endl;
    s.push(3);
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    return 0;
}