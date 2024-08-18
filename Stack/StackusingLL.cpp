#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = nullptr;
    }
};

class MyStack {
private:
    StackNode *topNode;

public:
    MyStack() {
        topNode = nullptr;
    }

    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (topNode == nullptr) return -1;
        int popped = topNode->data;
        StackNode* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return popped;
    }

    int top() {
        if (topNode == nullptr) return -1;
        return topNode->data;
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
    return 0;
}