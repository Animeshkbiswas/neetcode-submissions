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

    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==nullptr) return root;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            TreeNode* left=nullptr;
            TreeNode*  right=nullptr;
            if(temp->left!= NULL){
            q.push(temp->left);
            left= temp->left;
             }
            if(temp->right!= NULL){
            q.push(temp->right);
            right= temp->right;
             }
          
                TreeNode* j= left;
                temp->left= right;
                temp->right= j;
             
            
        }
        return root;
    }
};
