#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int currentMin = st.top().second;
            st.push({val, min(val, currentMin)});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        if (!st.empty()) {
            return st.top().first;
        }
        return -1;
    }

    int getMin() {
        if (!st.empty()) {
            return st.top().second;
        }
        return -1;
    }
};

int main() {
    MinStack minStack;
    minStack.push(2147483646);
    minStack.push(2147483646);
    minStack.push(2147483647);
    cout << minStack.top() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    minStack.push(2147483647);
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    minStack.push(-2147483648);
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    return 0;
}
