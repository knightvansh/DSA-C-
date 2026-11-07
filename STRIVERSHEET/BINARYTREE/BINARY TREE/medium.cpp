//https://leetcode.com/problems/path-sum/description/

  class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        
        if (root->left == NULL && root->right == NULL) {
            
            return targetSum == root->val; 
        }
       
        bool R1 = hasPathSum(root->left, targetSum - root->val);
 
        bool R2 = hasPathSum(root->right, targetSum - root->val);
       
        return R1 || R2;
    }
};





//https://leetcode.com/problems/deepest-leaves-sum/


























//https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution {
public:
       int solve(TreeNode* root, int& maxi) {
        if (root == NULL) return 0;

        int leftSum = max(0, solve(root->left, maxi));
        int rightSum = max(0, solve(root->right, maxi));
        maxi = max(maxi, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; 
        solve(root, maxi);
        return maxi;
    }
};







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



//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root ==NULL ||root==p|| root==q){
            return root;
        }
   TreeNode* left= lowestCommonAncestor(root->left,p,q);
   TreeNode* right= lowestCommonAncestor(root->right,p,q);

    if(left !=NULL && right !=NULL){
      return root;
      }
  if(left !=NULL){
    return left;
     }
     return right;
 }
};