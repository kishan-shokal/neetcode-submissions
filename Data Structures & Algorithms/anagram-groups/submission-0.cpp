class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto st:strs){
            auto tmp = st;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(st);
        }
        vector<vector<string>>ans;
        for(auto p:mp) ans.push_back(p.second);
        return ans;
    }
};
