class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int> &nums,int n,vector<int> &curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        solve(i+1,nums,n,curr);
        
        curr.push_back(nums[i]);
        solve(i+1,nums,n,curr);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr;
        solve(0,nums,n,curr);
        return ans;
    }
};
