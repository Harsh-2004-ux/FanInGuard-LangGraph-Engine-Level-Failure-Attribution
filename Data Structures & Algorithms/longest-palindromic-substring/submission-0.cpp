class Solution {
public:
    bool is_valid(int i,int j,string &s){

        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();

        string ans="";
        int max_len=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(is_valid(i,j,s)){
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        string t=s.substr(i,j-i+1);
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};
