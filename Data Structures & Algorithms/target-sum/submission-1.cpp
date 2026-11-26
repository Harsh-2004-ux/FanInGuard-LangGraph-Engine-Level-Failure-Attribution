class Solution {
public:
    int solve(int i,int offset,vector<int> &nums,int target,int sum,vector<vector<int>> &dp){

        if(i==nums.size()){
            if(target==offset) return 1;
            return 0;
        }

        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
        int pos=solve(i+1,offset+nums[i],nums,target,sum,dp);
        int neg=solve(i+1,offset-nums[i],nums,target,sum,dp);
        return dp[i][sum+offset]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int offset=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(2*sum+1,-1));
        return solve(0,offset,nums,target,sum,dp);
    }
};
