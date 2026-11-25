class Solution {
public:
    bool solve(int i,string &s,set<string> &st,vector<int> &dp){

        if(i==s.size()) return true;

        if(dp[i]!=-1) return dp[i];

        string curr="";

        for(int j=i;j<s.size();j++){

            curr.push_back(s[j]);
            if(st.find(curr)!=st.end()){
                if(solve(j+1,s,st,dp)){
                    return dp[i]=true;
                }
            }
        }

        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string> st;
        vector<int> dp(n,-1);
        for(auto word : wordDict){
             st.insert(word);
        }
        return solve(0,s,st,dp);
    }
};
