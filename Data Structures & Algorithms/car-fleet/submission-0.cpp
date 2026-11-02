class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,int>> p;

       int n=speed.size();

       for(int i=0;i<n;i++){
        p.push_back({position[i],speed[i]});
       } 

       sort(p.begin(),p.end());

       vector<int> res;

       for(auto it:p){
        int a=it.first;
        int b=it.second;
        int time=(target-a)/b;
        res.push_back(time);
       }

       stack<int> st;

       for(int i=res.size()-1;i>=0;i--){
        if(!st.empty() && res[i]<=st.top()){
            st.pop();
        }
        st.push(res[i]);
       }

       return st.size();
    }
};
