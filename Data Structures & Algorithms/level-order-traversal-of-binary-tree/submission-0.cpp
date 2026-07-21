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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>qu;
        if(root) qu.push(root);
        while(!qu.empty()){
            int n = qu.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                auto fr = qu.front();
                qu.pop();
                v.push_back(fr->val);
                if(fr->left) qu.push(fr->left);
                if(fr->right) qu.push(fr->right);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};
