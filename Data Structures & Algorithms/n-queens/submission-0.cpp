class Solution {
public:
    bool is_safe(int row,int col,vector<string> &grid,int n){
        int dupr=row;
        int dupc=col;

        while(dupr>=0 && dupc>=0){
            if(grid[dupr][dupc]=='Q') return false;
            dupr--,dupc--;
        }
        dupr=row;
        dupc=col;
        while(dupc>=0){
            if(grid[dupr][dupc]=='Q') return false;
            dupc--;
        }
        dupr=row;
        dupc=col;

        while(dupr<n && dupc>=0){
            if(grid[dupr][dupc]=='Q') return false;
            dupr++,dupc--;
        }

        return true;
    }
    void solve(int col,vector<string> &grid,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(grid);
            return;
        }

        for(int row=0;row<n;row++){
            if(is_safe(row,col,grid,n)){
                grid[row][col]='Q';
                solve(col+1,grid,ans,n);
                grid[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid(n,string(n,'.'));

        solve(0,grid,ans,n);
        return ans;
    }
};
