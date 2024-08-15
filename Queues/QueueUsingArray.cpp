#include<bits/stdc++.h>
using namespace std;

class stImpl {
    int Index = -1;
    int topEle=0;
    int arr[10000];
public:
    void push(int data) {
        if (Index >= 9999) {
            cout << "Queue Overflow" << endl;
            return;
        }
        Index++;
        arr[Index] = data;
    }
    
    void pop() {
        if (Index == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Index--;
        topEle++;
    }

    int size() {
        return Index + 1;
    }
    
    int top() {
        if (Index == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topEle];
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
    return 0;
}