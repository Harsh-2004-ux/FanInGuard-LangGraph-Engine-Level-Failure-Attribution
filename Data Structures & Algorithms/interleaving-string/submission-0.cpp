class Solution {
public:
    bool solve(int i,int j,int k,string &s1,string &s2,string &s3){
        if(k==s3.size() && i==s1.size() && j==s2.size()) return true;
        if(k>=s3.size()) return false;
        bool result=false;
        if(i<s1.size() && s1[i]==s3[k]){
            result=solve(i+1,j,k+1,s1,s2,s3);
        }
        if(i<s2.size() && s2[j]==s3[k]){
            result=solve(i,j+1,k+1,s1,s2,s3);
        }

        return result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i=0;
        int j=0;
        int k=0;
        return solve(0,0,0,s1,s2,s3);
    }
};
