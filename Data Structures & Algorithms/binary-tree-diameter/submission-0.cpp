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
    int ans = 0;
    int f(TreeNode*root){
        if(!root) return 0;
        int left_depth = f(root->left);
        int right_depth = f(root->right);
        ans = max(ans,left_depth+right_depth+1);
        return max(left_depth,right_depth)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        f(root);
        return ans-1;
    }
};
