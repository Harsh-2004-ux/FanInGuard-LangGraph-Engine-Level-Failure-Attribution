class Solution {
public:
    int solve(int l,int r,vector<int> &arr){
        int maxi=INT_MIN;
        for(int i=l;i<=r;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }
        return maxi;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        vector<int> ans;
        while(r<n){
            
            if(r-l+1>k){
                l++;
            }
            if(r-l+1==k){
                int maxi=solve(l,r,nums);
                ans.push_back(maxi);
            }
            r++;
        }

        return ans;
    }
};
