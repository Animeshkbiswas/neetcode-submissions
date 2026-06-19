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
    bool x =true;
    int height1(TreeNode* root){
        if(root==nullptr) return 0;
        int height=1;
        int heightleft= height1(root->left);
        int heightright= height1(root->right);
        height+= max(heightleft,heightright);
        if(abs(heightleft-heightright)>1){
            x= false;
        }
        return height;

    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        height1(root);
        return x;
    }
};
