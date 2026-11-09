class Solution {
public:
    vector<string> ans;
    bool isvalid(string &t){
        int cnt=0;

        for(int i=0;i<t.size();i++){
            if(t[i]=='(') cnt++;
            else{
                cnt--;
                if(cnt<0) return false;
            }
        }


        return cnt==0;
    }
    void solve(int i,int n,string &s){

        if(i==2*n){
            if(isvalid(s)){
                ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        solve(i+1,n,s);
        s.pop_back();
        s.push_back(')');
        solve(i+1,n,s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s;
        solve(0,n,s);
        return ans;
    }
};
