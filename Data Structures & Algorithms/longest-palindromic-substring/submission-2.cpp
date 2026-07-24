class Solution {
public:
    string longestPalindrome(string st) {
        int n = st.size();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        int x=0,s=1;
        for(int l=1;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                if(l==1) dp[i][i] =1;
                else if(st[i]==st[i+l-1]){
                    if(l==2) dp[i][i+l-1] = 1;
                    else if(dp[i+1][i+l-2]) dp[i][i+l-1] = 1;
                } 
                if(dp[i][i+l-1] && l>s) {
                    x=i;s=l;
                }
            }
            
        }
        return st.substr(x,s);
    }
};
