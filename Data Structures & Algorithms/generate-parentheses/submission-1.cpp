class Solution {
public:
    vector<string>ans;
    void dfs(int o,int c,string & st){
        if(o>c || o<0 || c<0) return ;
        if(o==0 && c==0){
            ans.push_back(st);
            return ;
        }
        st.push_back('(');
        dfs(o-1,c,st);
        st.pop_back();
        st.push_back(')');
        dfs(o,c-1,st);
        st.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string st;
        dfs(n,n,st);
        return ans;
    }
};
