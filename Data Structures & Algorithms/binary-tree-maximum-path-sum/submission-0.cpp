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
    int max1=INT_MIN;
    int findbest(TreeNode* root){
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr){
            max1=max(root->val,max1);
            return root->val;
        }
        int leftnotsplit=0;
        int rightnotsplit=0;
        if(root->left!=nullptr){
            leftnotsplit=max(0,findbest(root->left));
        }
        if(root->right!=nullptr){
            rightnotsplit=max(0,findbest(root->right));
        }
        int maxsplit=root->val+leftnotsplit+rightnotsplit;
        max1=max(maxsplit,max1);
        return (root->val+max(leftnotsplit,rightnotsplit));
    }
    int maxPathSum(TreeNode* root) {
        int a=findbest(root);
        if(root==nullptr) return 0;
        return max1;
    }
};
