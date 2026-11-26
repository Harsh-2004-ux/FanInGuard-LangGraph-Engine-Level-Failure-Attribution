class Solution {
public:
    int solve(int i,string &s,string &t,string curr){
        int n=s.size();

        if(i==n){
            if(curr==t) return 1;
            else return 0;
        }

        int nottake=solve(i+1,s,t,curr);
        curr.push_back(s[i]);
        int take=solve(i+1,s,t,curr);
        curr.pop_back();


        return take+nottake;
    }
    int numDistinct(string s, string t) {

        string curr="";
        return solve(0,s,t,curr);
    }
};
