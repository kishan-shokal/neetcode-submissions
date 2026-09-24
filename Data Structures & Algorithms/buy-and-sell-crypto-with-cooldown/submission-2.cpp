class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<int>&arr,int ind,bool buyed){
        if(ind>=arr.size()) return 0;
        if(dp[ind][buyed]!=INT_MIN) return dp[ind][buyed];
        int exclude = dfs(arr,ind+1,buyed);
        int include = 0;
        if(buyed) include = dfs(arr,ind+2,false) + arr[ind];
        else include = dfs(arr,ind+1,true) -arr[ind];
        return dp[ind][buyed]=max(include,exclude);
    }
    int maxProfit(vector<int>& prices) {
        dp.clear();
        int n = prices.size();
        dp.resize(n,vector<int>(2,INT_MIN));
        return dfs(prices,0,0);
    }
};
