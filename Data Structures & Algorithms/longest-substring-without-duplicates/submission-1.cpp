class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0,n=s.size();
        int i=0,j=0;
        set<char> st;
        while(j<n){
            while(st.count(s[j])){
                st.erase(s[i++]);
            }
            st.insert(s[j++]);
            int tm = st.size();
            ans=max(ans,tm);
            
        }
        return ans;
    }
};
