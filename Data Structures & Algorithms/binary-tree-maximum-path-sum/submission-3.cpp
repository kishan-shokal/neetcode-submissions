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
#define ll long long 
class Solution {
public:
    ll ans=INT_MIN;
    int f(TreeNode*root){

        if(!root) return INT_MIN;
        ll rv = root->val;
        ll lf = f(root->left)+rv;
        ll rt = f(root->right)+rv;

        
        ll tm = lf+rt-rv;
        ans = max({ans,lf,rt,tm,rv});
        return max({rv,lf,rt});
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        f(root);
        return ans;
    }
};
