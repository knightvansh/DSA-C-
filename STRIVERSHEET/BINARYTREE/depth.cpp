/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  DFS - Root पर खड़े हो जाएंगे और left subtree में maximum number of nodes calculate कर लेंगे, और फिर right subtree में भी maximum number of nodes calculate करेंगे। फिर दोनों में से जिसमें number of nodes maximum होगा, उसमें हम अपनी root node (+1) कर देंगे, जो कि हमारी depth और height कहलाएगी। Current complexity -O(n)//

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }   

    
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);

        return 1 + max(leftheight, rightheight); 
    }
};