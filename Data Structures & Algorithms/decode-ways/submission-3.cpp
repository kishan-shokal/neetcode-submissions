class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0 || s[0]=='0') return 0;
        
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i<n;i++){
            // if(i+1<n && s[i+1]=='0') 
            if(s[i]!='0')dp[i+1]=dp[i];
            int tm = (s[i-1]-'0' )*10 +s[i]-'0';
            if(tm==0) return 0;
            if(tm<=26 && s[i-1]!='0'){
                dp[i+1]+=dp[i-1];
            }
            
        }
        return dp[n];
    }
};
