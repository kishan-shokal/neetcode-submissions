class Solution {
public:
    vector<vector<int>> grid;
    int n ,m;
    vector<pair<int,int>>directions = {{1,0},{0,1},{0,-1},{-1,0}};
    int f(int x,int y){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!=1) return 0;
        int ans = 1;
        grid[x][y]=-1;
        for(auto dir:directions){
            ans+=f(x+dir.first,y+dir.second);
        }
        return ans;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,f(i,j));
            }
        }
        return ans;
    }
    
};
