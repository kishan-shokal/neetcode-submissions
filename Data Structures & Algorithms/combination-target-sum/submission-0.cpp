class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    
    void dfs(vector<int>&nums,int ind,int target){

        if(ind==nums.size()){
            if(target==0) ans.push_back(v);
            return ;
        }
        if(target<0) return ;
        dfs(nums,ind+1,target);
        v.push_back(nums[ind]);
        dfs(nums,ind,target-nums[ind]);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,0,target);
        return ans;
    }
};
