class Solution {
public:
    void solve(int i,string &curr,string &s,set<string> &st){
        if(i>=s.size()) return;
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
        solve(0,curr,s,st);

        if(st.empty()) return true;
        else return false;
    }
};
