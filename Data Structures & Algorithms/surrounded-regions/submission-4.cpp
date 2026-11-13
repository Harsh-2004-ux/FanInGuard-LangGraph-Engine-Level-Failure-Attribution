class Solution {
public:
    int dir1[4]={-1,0,1,0};
    int dir2[4]={0,-1,0,1};
    void solve(vector<vector<char>>& board,vector<vector<int>> &mat,int i,int j){

        int n=board.size();
        int m=board[0].size();
        mat[i][j]=0;
        for(int k=0;k<4;k++){
            int new_i=i+dir1[k];
            int new_j=j+dir2[k];

            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && board[new_i][new_j]=='O' && mat[new_i][new_j]==1){
                mat[new_i][new_j]=0;
                solve(board,mat,new_i,new_j);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> mat(n,vector<int>(m,1));

        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
            solve(board,mat,0,i);
            }
        } 

        for(int j=0;j<n;j++){
            if(board[j][0]=='O'){
            solve(board,mat,j,0);
            }
        }

        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
            solve(board,mat,n-1,i);
            }
        }

        for(int j=0;j<n;j++){
            if(board[j][m-1]=='O'){
            solve(board,mat,j,m-1);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) board[i][j]='X';
                else board[i][j]='O';
            }
        }
    }
};
