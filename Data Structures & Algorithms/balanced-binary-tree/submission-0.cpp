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
private:
    bool ans = true;
    int helper(TreeNode* root){
        if(!root) return false;
        int lh = helper(root->left);
        int rh = helper(root->right);
        int d = abs(lh-rh);
        ans = ans & ( d<=1);
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        helper(root);
        return ans;
    }
};
