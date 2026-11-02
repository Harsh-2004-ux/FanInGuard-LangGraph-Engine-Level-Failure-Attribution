class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,double>> p;

       int n=speed.size();

       for(int i=0;i<n;i++){
        p.push_back({position[i],speed[i]});
       } 

       sort(p.begin(),p.end());

       vector<double> res;

       for(auto it:p){
        int a=it.first;
        int b=it.second;
        double time=(double)(target-a)/b;
        res.push_back(time);
       }

       stack<double> st;

       for(int i=res.size()-1;i>=0;i--){
        if(!st.empty() && res[i]<=st.top()){
            st.pop();
        }
        st.push(res[i]);
       }

       return st.size();
    }
};
