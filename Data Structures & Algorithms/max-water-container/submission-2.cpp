class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        int i=0,j=n-1;

        while(i<j){
            int width=abs(j-i);
            int height=min(heights[i],heights[j]);
            int prod=width*height;
            ans=max(ans,prod);

            if(heights[j]>heights[i]) i++;
            else j--;
        }

        return ans;
    }
};
