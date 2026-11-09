class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int> &nums,int target,vector<int> &curr){
            if(target==0){
                ans.push_back(curr);
                return;
            }
            if(i==nums.size()) return;
        solve(i+1,nums,target,curr);
        if(target>=nums[i]){
        curr.push_back(nums[i]);
        solve(i,nums,target-nums[i],curr);
        curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> curr;
        solve(0,nums,target,curr);
        return ans;
    }
};
