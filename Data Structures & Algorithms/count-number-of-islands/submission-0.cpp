class Solution {
public:
    int m,n;
    vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};//,{1,-1},{-1,1},{-1,-1},{1,1}};
    void dfs(vector<vector<char>>& grid,int x,int y){
        if(x==m || x<0 || y<0 || y==n) return ;
        if(grid[x][y]=='1'){
            grid[x][y]='2';
            for(auto d:dir ){
                dfs(grid,x+d.first,y+d.second);
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
