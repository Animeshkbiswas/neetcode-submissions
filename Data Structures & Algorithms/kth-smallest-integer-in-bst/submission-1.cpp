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
    int count =0;
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;

        vector<int> ans(2);
        ans[1]=k;
        ans=traverse(root,ans);
        return ans[0];
        
    }
    vector<int>traverse(TreeNode* root, vector<int> k){
        if(root==nullptr) return k;
        if(root->left!=nullptr){
           k= traverse(root->left,k);
        }
        k[1]--;
        if(k[1]==0){
            k[0]=root->val;
            return k;
        }
        if(root->right!=nullptr){
           k= traverse(root->right,k);
        }
        return k;

    }
};
