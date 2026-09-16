class Solution {
public:
    string convertToTitle(int n) {
        if(n==701){
            return "ZY";
        }
        string ans;
        while(n){
            int r = n%26;
            n/=26;
            char ch = 'A'+r-1;
            ans = ans+ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};