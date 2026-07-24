class Solution {
public:
    int countSubstrings(string st) {
        int n = st.size();
        if(n==0) return 0;
        // int x=0,s=1;
        int ans=0;
        for( int m =0;m<n;m++){
            int i=m,j=m;


            while(i>=0 && j<n && st[i]==st[j]) j++,i--,ans++;
            i=m-1;j=m;
            if(m!=0 &&  st[i]==st[j]){
                // ans++;
                while(i>=0 && j<n && st[i]==st[j]) j++,i--,ans++;
            }
        }
        return ans;
    }
};
