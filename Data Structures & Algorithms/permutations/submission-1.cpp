class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int> &nums,vector<int> curr,vector<int> &vis){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int index=0;index<nums.size();index++){

            if(!vis[index]){
                vis[index]=1;
                curr.push_back(nums[index]);
                solve(nums,curr,vis);
                curr.pop_back();
                vis[index]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr;
        vector<int> vis(n,0);
        solve(nums,curr,vis);
        return ans;
    }
};