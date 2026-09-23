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
    int ans=INT_MIN;
    int f(TreeNode*root){

        if(!root) return INT_MIN;
        // if(!root->left && !root->right) return root->val;
        int rv = root->val;
        int lf = f(root->left);
        int rt = f(root->right);

        int tm = lf;

        if(lf!=INT_MIN) lf+=rv;
        if(rt!=INT_MIN) {
            if(tm!=INT_MIN)tm+=rt;
            rt+=rv;
        }
        if(tm!=INT_MIN) tm+=rv;
        
        ans = max({ans,lf,rt,tm,rv});
        return max({rv,lf,rt});
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        f(root);
        return ans;
    }
};
