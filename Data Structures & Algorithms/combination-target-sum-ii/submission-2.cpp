class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, int target, vector<int>& curr) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        for(int index=i;index<nums.size();index++){

            if(index>i && nums[index]==nums[index-1]) continue;
            if(nums[index]>target) break;

            curr.push_back(nums[index]);
            solve(index+1,nums,target-nums[index],curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,curr);
        return ans;
    }
};
