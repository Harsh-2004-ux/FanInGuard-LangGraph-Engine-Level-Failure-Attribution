class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void solve(int i, vector<int>& nums, int target, vector<int>& curr) {

        if(target == 0) {
            st.insert(curr);
            return;
        }

        if(i == nums.size()) {
            return;
        }

        solve(i+1, nums, target, curr);

        if(target >= nums[i]) {
            curr.push_back(nums[i]);
            solve(i+1, nums, target-nums[i], curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,curr);

        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
