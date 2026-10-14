class Solution {
public:
    int characterReplacement(string st, int k) {
        int n = st.size();
        int ans = 0;
        unordered_map<char,int>mp;
        int i = 0;
        int mx = 0;
        for(int j = 0;j<n;j++){
            mp[st[j]]++;
            mx = max(mx,mp[st[j]]);
            while(j-i+1-mx>k){
                mp[st[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);

        }
        return ans;
    }
};
