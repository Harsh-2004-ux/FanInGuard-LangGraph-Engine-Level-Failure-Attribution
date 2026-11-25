class Solution {
public:
    bool solve(int i,string &curr,string &s,set<string> &st){
        if(i>=s.size()) return false;
        if(st.empty()) return true;
        if(st.find(curr)!=st.end()){
            st.erase(curr);
        }
        solve(i+1,curr,s,st);
        curr.push_back(s[i]);
        solve(i+1,curr,s,st);
        curr.pop_back();

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        set<string> st;
        string curr="";
        if(solve(0,curr,s,st)) return true;
        return false;
    }
};
