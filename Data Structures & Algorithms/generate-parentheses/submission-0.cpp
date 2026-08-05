class Solution {
public:
    vector<string>ans;
    void dfs(int o,int c,string st){
        if(o>c || o<0 || c<0) return ;
        if(o==0 && c==0){
            ans.push_back(st);
            return ;
        }
        dfs(o-1,c,st+"(");
        dfs(o,c-1,st+")");
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,n,"");
        return ans;
    }
};
