class Solution {


    vector<string>mt;
    vector<vector<string>>ans;
    bool check(int n ,int x,int y ){
        
        for(int col=0;col<n;col++){
            if(mt[col][y]=='Q') return false;
        }
    
        for (int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
            if (mt[i][j] == 'Q') return false;
        for (int i = x-1, j = y+1; i >= 0 && j < n; i--, j++)
            if (mt[i][j] == 'Q') return false;
        return true;

    }
    void helper(int n,int x){
        if(x==n){
            ans.push_back(mt);
            return ;
        }
        for(int y=0;y<n;y++){
        
            bool ch = check(n,x,y);
            if(ch){
                mt[x][y]='Q';
                helper(n,x+1);
                mt[x][y]='.';
            }
        }
        


    }
public:

    
    vector<vector<string>> solveNQueens(int n) {
        mt.assign(n, string(n, '.'));
        ans.clear();
        helper(n,0);
        return ans;


    }
};
