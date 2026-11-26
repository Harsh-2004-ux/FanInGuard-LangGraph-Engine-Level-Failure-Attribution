class Solution {
public:
    bool solve(int i,int j,int k,string &s1,string &s2,string &s3, vector<vector<vector<int>>> &dp){
        if(k==s3.size() && i==s1.size() && j==s2.size()) return true;
        if(k>=s3.size()) return false;

        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool result=false;
        if(i<s1.size() && s1[i]==s3[k]){
            result=solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(i<s2.size() && s2[j]==s3[k]){
            result=solve(i,j+1,k+1,s1,s2,s3,dp);
        }

        return dp[i][j][k]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i=0;
        int j=0;
        int k=0;
        int n=s1.size();
        int m=s2.size();
        int t=s3.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(t+1,-1)));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};
