class Solution {
public:
    vector<string>ans;
    string st,word;
    int n ;
    unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    void dfs(int ind){
        if(ind==n){
            if(word!="") ans.push_back(word);
            return ;
        }
        for(auto c : mp[st[ind]]){
            word+=c;
            dfs(ind+1);
            word.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        st = digits;
        n = st.size();
        dfs(0);
        return ans;
    }
};
