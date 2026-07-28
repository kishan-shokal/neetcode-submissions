class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int> & coins,int ind,int amount){
        if(amount==0) return 0;
        if(amount<0 || ind == coins.size()) return INT_MAX;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take = helper(coins,ind,amount-coins[ind]);
        int notTake = helper(coins,ind+1,amount);
        if(take!=INT_MAX) take++;
        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        int ans = helper(coins,0,amount);
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};
