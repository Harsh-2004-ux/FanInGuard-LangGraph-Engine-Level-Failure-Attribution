class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights,int n){
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> prevSmaller(vector<int>& heights,int n){
        stack<int> st;
        vector<int> ans(n);

        for(int i=0;i<n;i++){

            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> next(n);
        next=nextSmaller(heights,n);
        vector<int> prev(n);
        prev=prevSmaller(heights,n);

        int maxi=0;
        for(int i=0;i<n;i++){
            int l=heights[i];

            if(next[i]==-1){
                next[i]=n;
            }

            int b=next[i]-prev[i]-1;

            maxi=max(maxi,l*b);
        }

        return maxi;
    }
};
