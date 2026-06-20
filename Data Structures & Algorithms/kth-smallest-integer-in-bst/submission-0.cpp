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
    int sizeoftree(TreeNode* root){
        if(root==nullptr) return 0;
        int size=1;
       if(root->left!=nullptr){ size+=sizeoftree(root->left);}
       if(root->right!=nullptr){ size+=sizeoftree(root->right);}
        return size;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int leftSize = sizeoftree(root->left);

        if(leftSize+1==k){
            ans=root->val;
        }
        else if(leftSize >= k) return kthSmallest(root->left, k);
    else 
    return kthSmallest(root->right, k - leftSize - 1);
    return ans;
    }
};
