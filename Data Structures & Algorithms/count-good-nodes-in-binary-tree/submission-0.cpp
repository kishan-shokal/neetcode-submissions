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
    int ans ;
    void f(TreeNode* root,int mx){
        if(!root) return ;
        if(root->val>=mx) ans++;
        
        f(root->left,max(mx,root->val));
        f(root->right,max(mx,root->val));
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        f(root,INT_MIN);
        return ans;
    }
};
