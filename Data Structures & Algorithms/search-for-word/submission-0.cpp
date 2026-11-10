class Solution {
public:
    int dir1[4]={0,1,-1,0};
    int dir2[4]={1,0,0,-1};
    bool is_present(int i,int j, vector<vector<int>> &vis,vector<vector<char>>& board,string &target,string &curr){
        int n=board.size();
        int m=board[0].size();


        if(board[i][j]!=target[curr.size()]) return false;
        vis[i][j]=1;
        curr.push_back(board[i][j]);
        if(curr.size()==target.size()) return true;
        for(int k = 0; k < 4; k++) {

            int new_i = i + dir1[k];
            int new_j = j + dir2[k];

            if(new_i >= 0 && new_i < n &&
               new_j >= 0 && new_j < m &&
               vis[new_i][new_j] != 1) {

                if(is_present(new_i, new_j, vis, board, target, curr))
                    return true;
            }
        }

        vis[i][j]=0;
        curr.pop_back();


        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        string curr="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(is_present(i,j,vis,board,word,curr)){
                    return true;
                }
            }
        }
        return false;
    }
};
