class Solution {
public:
    int dir1[4]={1,0,-1,0};
    int dir2[4]={0,1,0,-1};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &vis,int r,int c){

        int n=heights.size();
        int m=heights[0].size();

        vis[r][c]=true;

        for(int k=0;k<4;k++){
            int new_r=r+dir1[k];
            int new_c=c+dir2[k];

            if(new_r<0 || new_r>=n || new_c<0 || new_c>=m) continue;
            if(vis[new_r][new_c]==true) continue;
            if(heights[new_r][new_c]>=heights[r][c]){
                dfs(heights,vis,new_r,new_c);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            dfs(heights,pacific,0,i);
        }
        
        for(int j=0;j<n;j++){
            dfs(heights,pacific,j,0);
        }
        //Atlantic;

        for(int i=0;i<m;i++){
            dfs(heights,atlantic,n-1,i);
        }

        for(int j=0;j<n;j++){
            dfs(heights,atlantic,j,m-1);
        }
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};