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
    int global_height=0;
    int height1(TreeNode* root){
        if(root==nullptr) return 0;
        int height =1;
        int leftheight= height1(root->left);
        int rightheight= height1(root->right);
        global_height= max(global_height,leftheight+rightheight);
        height+= max(leftheight,rightheight);
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        height1(root->left);
        height1(root->right);
        height1(root);
        return global_height;
    }
};
