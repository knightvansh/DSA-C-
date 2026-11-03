

// 199. Binary Tree Right Side
// https://leetcode.com/problems/binary-tree-right-side-view/description/
class Solution {
  void right(TreeNode* root,int level,vector<int>& ans){
  if(root == NULL){
    return;
    } 
  if(level == ans.size()){
    ans.push_back(root->val);
  }
right(root->right,level + 1,ans);
right(root->left,level + 1,ans);

 }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        right(root,0,ans);
        return ans;
    }
};