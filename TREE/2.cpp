#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // Helper function returns the height of the current node,
    // while continuously updating maxDia by reference.
    int calculateHeight(TreeNode* root, int& maxDia) {
        // Line 1: Base Case — An empty node has a height of 0
        if (root == NULL) {
            return 0;
        }

        // Line 2: Recursively find the height of the left subtree
        int leftHeight = calculateHeight(root->left, maxDia);

        // Line 3: Recursively find the height of the right subtree
        int rightHeight = calculateHeight(root->right, maxDia);

        // Line 4: Calculate path passing through CURRENT node as turning point,
        // and update maxDia if this path is longer than any previously seen path.
        maxDia = max(maxDia, leftHeight + rightHeight);

        // Line 5: Return height of current node back to its parent call
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        calculateHeight(root, maxDia);
        return maxDia;
    }
};