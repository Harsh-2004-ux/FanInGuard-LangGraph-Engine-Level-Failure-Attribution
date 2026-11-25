class Solution {
public:
    bool solve(int i,vector<int> &nums,int target,vector<vector<int>> &dp){
        int n=nums.size();
        if(i==n) return false;
        if(target==0) return true;

        if(dp[i][target]!=-1) return dp[i][target];
        bool take=false;
        if(target>=nums[i]){
            take=solve(i+1,nums,target-nums[i],dp);
        }
        bool nottake=solve(i+1,nums,target,dp);

        return dp[i][target]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int a=accumulate(nums.begin(),nums.end(),0);
        if(a%2!=0) return false;
        int target=a/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};
