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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        string ans;
        ans+=to_string(root->val);
        ans.push_back(' ');
       if(root->left==nullptr){
        ans+="N ";
       }
       else if(root->left!=nullptr){
        ans+=serialize(root->left);
        }
        if(root->right==nullptr){
        ans+="N ";
       }
       else if(root->right!=nullptr){
        ans+=serialize(root->right);
        }
        return ans;
        
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* temp;
        if(data=="") return nullptr;
        stringstream ss(data);
        temp= build(ss);
        return temp;
        
    }
    TreeNode* build(stringstream &ss){
        string s;
        ss>>s;
        if(s=="N") return nullptr;
        TreeNode* root= new TreeNode (stoi(s));
        root->left = build(ss);
        root->right = build(ss);
         return root;

    } 

};
