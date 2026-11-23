class Solution {
public:
    string solve(int i,int j,string &s){

        string res="";
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }

        i++;
        j--;

        res=s.substr(i,j-i+1);

        return res;
    }
    string longestPalindrome(string s) {
        
        string ans="";
        int n=s.size();

        for(int i=0;i<n;i++){

            string odd=solve(i,i,s);

            string even=solve(i,i+1,s);

            if(odd.size()>ans.size()) ans=odd;
            if(even.size()>ans.size()) ans=even;
        }

        return ans;
    }
};
