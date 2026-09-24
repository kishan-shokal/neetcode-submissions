class Solution {
public:
    vector<vector<vector<int>>>dp;
    int f(vector<int>&arr,int ind,int cnb,int pr){
        if(ind>=arr.size()) return 0;
        int ans = 0;
        if(dp[ind][pr][cnb]!=INT_MIN) return dp[ind][pr][cnb];
        if(cnb){
            ans = f(arr,ind+1,0,ind+1);
            ans = max(ans,f(arr,ind+1,1,0));
        }
        else{
            if(pr!=0) {
                ans = max(ans,f(arr,ind+1,0,pr));
                ans = max(ans,f(arr,ind+1,0,0)+arr[ind]-arr[pr-1]);

            }
            else {
                ans = max(ans,f(arr,ind+1,1,0));
            }
        }
        
        dp[ind][pr][cnb]=ans;
        
        return ans;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.clear();
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,INT_MIN)));
        return f(prices,0,1,0);   
    }
};
