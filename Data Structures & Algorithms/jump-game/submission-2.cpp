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
        dp.resize(n,0);
        dp[0]=true;
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            for(int j=i+1;j-i<=nums[i] && j<n;j++){
                dp[j]=true;
            }
        }
        return dp[n-1];
        
    }
};
