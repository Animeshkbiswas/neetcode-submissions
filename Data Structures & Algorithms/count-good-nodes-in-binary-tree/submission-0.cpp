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

class Solution {
public:
    int dfs(TreeNode* root,int maxVal){
            int ans=0;
            if(root==nullptr) return 0;
            if(root->val>=maxVal){
                ans=1;
            }
            maxVal= max(maxVal,root->val);
          if(root->left!=nullptr) {
            ans+=dfs(root->left,maxVal);
          } 
          if(root->right!=nullptr) {
            ans+=dfs(root->right,maxVal);
          }
          return ans; 
        }
    int goodNodes(TreeNode* root) {
     return dfs(root,root->val);
    }
};
