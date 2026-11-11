class Solution {
public:
    int maxi=0;
    int dir1[4]={-1,0,1,0};
    int dir2[4]={0,1,0,-1};
    void solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>> &vis,int &cnt){
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int new_i=i+dir1[k];
            int new_j=j+dir2[k];

            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && vis[new_i][new_j]==0 && grid[new_i][new_j]==1){
                vis[new_i][new_j]=1;
                solve(new_i,new_j,grid,vis,cnt+=1);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j]=1;
                    cnt+=1;
                    solve(i,j,grid,vis,cnt);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
