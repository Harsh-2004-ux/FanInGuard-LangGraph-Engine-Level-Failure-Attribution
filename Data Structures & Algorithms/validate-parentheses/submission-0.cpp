class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            if(s[i]='(') st.push(s[i]);
            if(s[i]='[') st.push(s[i]);
            if(s[i]='{') st.push(s[i]);

            else{
                if(st.empty()  || st.top()!=s[i]) return false;
                else st.pop();
            }
        }
        return true;
    }
};
