class Solution {
public:
    int dir1[4]={-1,0,1,0};
    int dir2[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int maxi=0;
        int cnt_1=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int i=it.first.first;
            int j=it.first.second;
            int t=it.second;
            maxi=max(maxi,t);
            for(int k=0;k<4;k++){
                int new_i=i+dir1[k];
                int new_j=j+dir2[k];

                if(new_i<n && new_i>=0 && new_j<m && new_j>=0 && vis[new_i][new_j]==0 && grid[new_i][new_j]==1){
                    q.push({{new_i,new_j},t+1});
                    vis[new_i][new_j]=2;
                    cnt_1++;
                }
            }
        }


        if(cnt==cnt_1) return maxi;
        return -1;
    }
};
