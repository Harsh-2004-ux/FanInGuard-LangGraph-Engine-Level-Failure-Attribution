class Solution {
public:
    int solve1(int i,vector<int> &s,vector<int> &dp1){
        if(i==s.size()-1) return s[s.size()-1];
        else if(i>=s.size()) return 0;

        if(dp1[i]!=-1) return dp1[i];
        int t=s[i]+solve1(i+2,s,dp1);
        int nt=solve1(i+1,s,dp1);
        return dp1[i]=max(t,nt);
    }
    int solve2(int i,vector<int> &t,vector<int> &dp2){
        if(i==t.size()-1) return t[t.size()-1];
        else if(i>=t.size()) return 0;
        if(dp2[i]!=-1) return dp2[i];
        int take=t[i]+solve2(i+2,t,dp2);
        int nt=solve2(i+1,t,dp2);
        return dp2[i]=max(take,nt);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> s(nums.begin()+1,nums.end());
        vector<int> t(nums.begin(),nums.end()-1);
        int n=s.size();
        int m=t.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(m,-1);
        int a=solve1(0,s,dp1);
        int b=solve2(0,t,dp2);
        return max(a,b);
    }
};
