class Solution {
public:
    int solve(int index,vector<int> &cost,vector<int> &dp){
        int n=cost.size();
        if(index==n) return 0;

        if(index>n) return 1e9;

        if(dp[index]!=-1) return dp[index];
        int a=cost[index]+solve(index+1,cost,dp);
        int b=cost[index]+solve(index+2,cost,dp);
        return dp[index]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int a=solve(0,cost,dp1);
        int b=solve(1,cost,dp2);
        int res=min(a,b);
        return res;
    }
};
