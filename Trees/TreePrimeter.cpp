// Mark the tress along the perimeter starting from the root point in a anti clockwise direction
// OR Boundary traversal of Binary tree

#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void printBoundary(TreeNode* root) {
        if (root == nullptr)
            return;

        // Print the root node
        cout << root->val << " ";

        // Print the left boundary in top-down manner, excluding leaf nodes
        printLeftBoundary(root->left);

        // Print all leaf nodes
        printLeaves(root->left);
        printLeaves(root->right);

        // Print the right boundary in bottom-up manner, excluding leaf nodes
        printRightBoundary(root->right);
    }

private:
    void printLeftBoundary(TreeNode* node) {
        if (node == nullptr)
            return;

        if (node->left) {
            // Print the node if it's not a leaf
            cout << node->val << " ";
            printLeftBoundary(node->left);
        } else if (node->right) {
            // If there is no left child, print the right child if it's not a leaf
            cout << node->val << " ";
            printLeftBoundary(node->right);
        }
        // Do nothing if it is a leaf node
    }

    void printLeaves(TreeNode* node) {
        if (node == nullptr)
            return;

        printLeaves(node->left);
        if (node->left == nullptr && node->right == nullptr)
            cout << node->val << " ";
        printLeaves(node->right);
    }

    void printRightBoundary(TreeNode* node) {
        if (node == nullptr)
            return;

        if (node->right) {
            // First recur for the right child
            printRightBoundary(node->right);
            // Print the node if it's not a leaf
            cout << node->val << " ";
        } else if (node->left) {
            // If there is no right child, print the left child if it's not a leaf
            printRightBoundary(node->left);
            cout << node->val << " ";
        }
        // Do nothing if it is a leaf node
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = node->right = nullptr;
    return node;
}

// Example usage
int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution solution;
    cout << "Boundary traversal of the binary tree is:" << endl;
    solution.printBoundary(root);

    return 0;
}
