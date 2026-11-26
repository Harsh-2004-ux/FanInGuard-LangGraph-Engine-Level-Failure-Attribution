class Solution {
public:
    int solve(int i,int offset,vector<int> &nums,int target){

        if(i==nums.size()){
            if(target==offset) return 1;
            return 0;
        }

        int pos=solve(i+1,offset+nums[i],nums,target);
        int neg=solve(i+1,offset-nums[i],nums,target);
        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int offset=0;
        return solve(0,offset,nums,target);
    }
};
