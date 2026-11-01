class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(')');
            else if(s[i]=='[') st.push(']');
            else if(s[i]=='{') st.push('}');

            else{
                if(st.empty()  || st.top()!=s[i]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
