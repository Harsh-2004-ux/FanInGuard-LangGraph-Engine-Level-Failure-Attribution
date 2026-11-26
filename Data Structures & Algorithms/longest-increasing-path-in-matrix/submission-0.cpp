class Solution {
public:
    int d1[4]={-1,0,0,1};
    int d2[4]={0,-1,1,0};
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n=matrix.size();
        int m=matrix[0].size();

        if(dp[i][j]!=-1) return dp[i][j];
        int len=1;
        for(int k=0;k<4;k++){
            int new_i=i+d1[k];
            int new_j=j+d2[k];

            if(new_i<n && new_i>=0 && new_j<m && new_j>=0 && matrix[i][j]<matrix[new_i][new_j]){
                len=max(len,1+solve(new_i,new_j,matrix,dp));
            }
        }

        return dp[i][j]=len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int res=solve(i,j,matrix,dp);
                maxi=max(maxi,res);
            }
        }
        return maxi;
    }
};
