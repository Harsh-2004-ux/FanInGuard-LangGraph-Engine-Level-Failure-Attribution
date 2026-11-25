class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int a=accumulate(nums.begin(),nums.end(),0);
        if(a%2==0) return true;
        return false;
    }
};
