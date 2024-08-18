#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); ++i) {        //reversing the queue after every operation
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int popped = q.front();
        q.pop();
        return popped;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.top() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.top() << endl;
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
    stack.pop();
    stack.pop();
    cout << "Is stack empty after popping all elements? " << (stack.empty() ? "Yes" : "No") << endl; // Should output Yes
    return 0;
}
