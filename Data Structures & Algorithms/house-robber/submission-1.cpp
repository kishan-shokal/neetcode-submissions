class Solution {
public:
    vector<vector<int>>dp;
    int f(vector<int>&nums,int ind,bool prev){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int exclude =0,include=0;
        exclude = f(nums,ind+1,false);
        if(!prev) include = f(nums,ind+1,true)+nums[ind];
        dp[ind][prev]=max(include,exclude);
        return dp[ind][prev];
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size(),vector<int>(2,-1));
        return f(nums,0,false);
    }
};
