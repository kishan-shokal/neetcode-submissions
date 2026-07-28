class Solution {
public:
    int helper(vector<int> & coins,int ind,int amount){
        if(amount==0) return 0;
        if(amount<0 || ind == coins.size()) return -1;
        int take = helper(coins,ind,amount-coins[ind]);
        int notTake = helper(coins,ind+1,amount);
        int ans = -1;
        if(take!=-1) ans = take+1;
        if(ans==-1) ans= notTake;
        if(notTake!=-1 ) ans=min(ans,notTake);
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int ans = helper(coins,0,amount);
        return ans;
    }
};
