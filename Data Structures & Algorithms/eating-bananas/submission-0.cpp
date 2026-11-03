class Solution {
public:
    int solve(vector<int> &piles,int  mid){
        int c=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            c+=(piles[i]+mid-1)/mid;
        }
        return c;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            int hrs=solve(piles,mid);

            if(hrs>h) l=mid+1;
            else{
                ans=mid;
                r=mid-1;
            }
        }

        return ans;
    }
};
