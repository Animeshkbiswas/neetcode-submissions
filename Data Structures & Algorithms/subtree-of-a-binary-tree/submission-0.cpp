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
    bool isSametree(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr&& subRoot==nullptr) return true;
        if(root==nullptr) return false;
        if(subRoot==nullptr) return false;
        if(root->val!= subRoot->val) return false;
        else if(root->val== subRoot->val){
            bool left,right;
           left= isSametree(root->left,subRoot->left);
           right=isSametree(root->right, subRoot->right);
           if(left&&right){
            return true;
           }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot){
            return true;
        }
        if(!root){
            return false;
        }
       if (isSametree(root,subRoot)){
        return true;
       }
       return isSubtree(root->left, subRoot)|| isSubtree(root->right,subRoot);

    }
};
