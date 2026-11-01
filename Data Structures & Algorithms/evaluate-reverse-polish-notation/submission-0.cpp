class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto c:tokens){
            if(c=="+" || c=="*" || c=="-" || c=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int ans=0;
                if(c == "+") ans = b+a;
                else if(c == "-") ans = b-a;
                else if(c == "*") ans = b*a;
                else if(c == "/") ans = b/a;
                st.push(ans);
            }
            else{
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};
