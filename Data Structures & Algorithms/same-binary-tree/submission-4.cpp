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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&& q==nullptr) return true;
        else if(p!=nullptr&& q==nullptr|| p==nullptr&& q!=nullptr) return false;
        if(p->val!= q->val){
          return false;
        };
        bool ans1, ans2;
        ans1=isSameTree(p->left, q->left);
        ans2=isSameTree(p->right, q->right);
        if(ans1==false||ans2==false){
            return false;
        }
     return true;
    }
};
