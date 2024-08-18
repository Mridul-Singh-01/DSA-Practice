#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {      // 3 important steps first
        while(st1.size()){  // first st1 -> st2
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);    //second push X to st1
        while(st2.size()){  //third st2 -> st1
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if(st1.empty())return -1;
        int poped=st1.top();
        st1.pop();
        return poped;
    }
    
    int peek() {
        if(st1.empty()) return -1;
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << "Popped: " << obj->pop() << endl;
    cout << "Popped: " << obj->pop() << endl;
    cout << "Peek: " << obj->peek() << endl;
    cout << "Is Empty: " << obj->empty() << endl;
    cout << "Popped: " << obj->pop() << endl;
    cout << "Is Empty: " << obj->empty() << endl;
    delete obj;
    return 0;
}