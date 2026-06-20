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
    bool dfs(TreeNode* root, int minVal, int maxVal){
        if(root==nullptr) return true;
        bool ansroot=true;
        bool ansleft=true;
        bool ansright=true;
        if(root->val>minVal && root->val<maxVal){
            ansroot=true;
        }
        else{
            ansroot= false;
        }
       int minValueleft=minVal;
       int maxValueleft=min(maxVal,root->val);
       int minValueright=max(minVal,root->val);
       int maxValueright=maxVal;
       if(root->left!=nullptr){ansleft=dfs(root->left,minValueleft, maxValueleft);}
       if(root->right!=nullptr){ansright=dfs(root->right,minValueright,maxValueright);}
       if(ansleft&&ansright&&ansroot){
        return true;
       }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-10000,10000);
    }
};
