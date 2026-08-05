class Solution {
public:
    vector<vector<char>> mt;
    string word;
    int n,m;
    vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool dfs(int x,int y,int ind){
        if(ind==word.size()) return true;
        if(x<0 || y < 0 || x==n || y==m || mt[x][y]!=word[ind]) return false;
        auto prv = mt[x][y];
        mt[x][y]='#';
        for(auto d : dir){
            if (dfs(x+d.first,y+d.second,ind+1)) return true;
        }
        mt[x][y]=prv;
        return false;

        
    }

    bool exist(vector<vector<char>>& board, string word) {
        mt = board;
        this->word = word;
        n = mt.size();
        m=mt[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,0)) return true;
            }
        }
        return false;


    }
};
