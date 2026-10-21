class Solution {
public:
    vector<int>dp;
    bool dfs(vector<int>&arr,int ind){
        if(ind>=arr.size()-1) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<=arr[ind];i++){
            if(dfs(arr,ind+i)) return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        dp.resize(n,-1);
        return dfs(nums,0);
        
    }
};
