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
    vector<int>ans;
    void f(TreeNode*root,int h){
        if(!root) return ;
        if(ans.size()==h) ans.push_back(root->val);
        f(root->right,h+1);
        f(root->left,h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        f(root,0);
        return ans;
    }
};
