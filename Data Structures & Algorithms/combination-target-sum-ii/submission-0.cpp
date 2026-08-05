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
        int tmi=ind;
        while(tmi<nums.size() && nums[tmi]==nums[ind]) tmi++;
        dfs(nums,tmi,target);
        v.push_back(nums[ind]);
        dfs(nums,ind+1,target-nums[ind]);
        v.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target);
        return ans;
    }
};
