#include<bits/stdc++.h>
using namespace std;

class stImpl {
    int topIndex = -1;
    int arr[10000];
public:
    void push(int data) {
        if (topIndex >= 9999) {
            cout << "Stack Overflow" << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = data;
    }
    
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        topIndex--;
    }

    int size() {
        return topIndex + 1;
    }
    
    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }
};

int main() {
    stImpl s;
    s.push(1);
    s.push(2);
    s.pop();
    s.pop();
    cout << s.top() << endl;
    s.push(1);
    cout << s.top() << endl;
    cout << s.size() << endl;
    return 0;
}