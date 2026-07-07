class Solution {
private:
    vector<vector<char>>board;
    bool check(int x,int y,char cr ){
        set<char>st;
        for(int i=0;i<9;i++) {
            if(board[i][y]=='.') continue;
            if(st.count(board[i][y])) return false;
            st.insert(board[i][y]);
            // if(board[i][y]==cr) return false;
        }
        st.clear();
        for(int j=0;j<9;j++) {
            if(board[x][j]=='.') continue;
            if(st.count(board[x][j])) return false;
            st.insert(board[x][j]);
            // if(board[x][j]==cr) return false;
        }
        st.clear();
        int sx = x-x%3;;
        int sy = y-y%3;
        for(int i=0;i<3;i++){
            int a = sx+i;
            for(int j = 0;j<3;j++){
                int b = sy+j;
                if(board[a][b]=='.') continue;
                if(st.count(board[a][b])) return false;
                st.insert(board[a][b]);  
                // if(board[a][b]==cr) return false;
            }
        }
        return true;
    }
    bool helper(int x,int y){
        for(int i=0;i<9;i++){
            for(int j =0;j<9;j++){
                bool ch = check(i,j,'a');
                if(not ch)return false;
            }
        }
        return true;
        if(x==9) return true;
        if(y==9 ) return helper(x+1,0);
        if(board[x][y]!='.') return helper(x,y+1);
        
        for(int i=1;i<=9;i++){
            char cr  = '0'+i;
            board[x][y]=cr;
            bool isValid = check(x,y,cr);
            if(isValid){
                
                if(helper(x,y+1)) return true;
            }
            board[x][y]='.';
        }
        return false;
    }
public:


    bool isValidSudoku(vector<vector<char>>& board) {
        this->board=board;
        return helper(0,0);

    }
};
