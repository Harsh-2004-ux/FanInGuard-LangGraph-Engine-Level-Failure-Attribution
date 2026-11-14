class Solution {
public:
    vector<string> ans;
    int dir1[4]={-1,0,0,1};
    int dir2[4]={0,1,-1,0};
    void solve(int i,int j,vector<vector<char>>& board,vector<vector<int>> &vis,string &t,string &s){
        int n=board.size();
        int m=board[0].size();
        vis[i][j]=1;
        if(t==s){
            ans.push_back(s);
            return;
        }
        if(s.size()>=t.size()) return;
        for(int k=0;k<4;k++){
            int new_i=i+dir1[k];
            int new_j=j+dir2[k];

            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && s.size() < t.size() && vis[new_i][new_j]!=1 && board[new_i][new_j]==t[s.size()]){
                s.push_back(board[new_i][new_j]);
                solve(new_i,new_j,board,vis,t,s);
                s.pop_back();
            }
        }
        vis[i][j]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        for(auto it:words){
            string t=it;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]==t[0]){
                        string s="";
                        vector<vector<int>> vis(n,vector<int>(m,0));
                        s.push_back(board[i][j]);
                        solve(i,j,board,vis,t,s);
                    }
                }
            }
        }
        return ans;
    }
};
