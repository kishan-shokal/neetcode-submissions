class Solution {
public:
    int countSubstrings(string st) {
        int n = st.size();
        if(n==0) return 0;
        int ans=0;
        for( int m =0;m<n;m++){
            int i=m,j=m;
            while(i>=0 && j<n && st[i]==st[j]) j++,i--,ans++;
            i=m-1;j=m;
            while(i>=0 && j<n && st[i]==st[j]) j++,i--,ans++;
          
        }
        return ans;
    }
};
