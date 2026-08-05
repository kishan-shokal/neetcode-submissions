class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    int n ;
    void dfs(vector<int>&nums,int ind){
        if(ind==n){
            ans.push_back(v);
            return ;
        }
        v.push_back(nums[ind]);
        dfs(nums,ind+1);
        v.pop_back();
        ind++;
        while(ind<n && nums[ind]==nums[ind-1]) ind++;
        dfs(nums,ind);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        dfs(nums,0);
        return ans;
    }
};
