class Solution {
public:
    vector<string> ans;
    void solve(int i,string &curr,string &digits,vector<string> &a){
        
        if(i>=digits.size()){
            ans.push_back(curr);
            return;
        }

        int digit=digits[i]-'0';
        string val=a[digit];

        for(int j=0;j<val.size();j++){
            curr.push_back(val[j]);
            solve(i+1,curr,digits,a);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
        vector<string> a={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curr="";
        solve(0,curr,digits,a);
        return ans;
    }
};