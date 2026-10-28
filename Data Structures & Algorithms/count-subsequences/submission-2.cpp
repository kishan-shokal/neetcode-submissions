class Solution {
public:
    int ans ;
    vector<vector<int>>dp;
    int f(string & s, string & t,int ind, int m ){
        if(m==t.size()) return 1;
        if(ind>=s.size()) return 0;
        if(dp[ind][m]!=-1) return dp[ind][m];
        int a = f(s,t,ind+1,m),b=0;
        if(s[ind]==t[m]) b=f(s,t,ind+1,m+1);
        return dp[ind][m]=a+b;
    }
    int numDistinct(string s, string t) {
        ans = 0;
        dp.clear();
        dp.resize(s.size(),vector<int>(t.size()+1,-1));
        ans = f(s,t,0,0);
        return ans;
    }
};
