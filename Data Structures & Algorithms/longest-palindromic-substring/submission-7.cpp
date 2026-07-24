class Solution {
public:
    string longestPalindrome(string st) {

        // Time O(n^2) Space (n^2)
        int n = st.size();
        if(n==0) return "";
        int x=0,s=1;
        for( int m =0;m<n;m++){
            int i=m,j=m;
            while(i>=0 && st[i]==st[m]) i--;
            while(j<n && st[j]==st[m]) j++;
            while(i>=0 && j<n && st[i]==st[j]) j++,i--;
            if(j-i-1>s){
                x = i+1;
                s = j-i-1;
            }
        }
        return st.substr(x,s);
        
    }
};
