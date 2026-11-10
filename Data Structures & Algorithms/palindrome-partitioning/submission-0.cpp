class Solution {
public:
    vector<vector<string>> res;
    bool is_pallindrome(string &t){
        string rev=t;
        reverse(rev.begin(),rev.end());
        return rev==t;
    }
    void solve(int i,string &s,vector<string> &curr){

        if(s.size()==i){
            res.push_back(curr);
            return;
        }

        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);

            if(is_pallindrome(temp)){
                curr.push_back(temp);
                solve(j+1,s,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        solve(0,s,ans);
        return res;
    }
};
