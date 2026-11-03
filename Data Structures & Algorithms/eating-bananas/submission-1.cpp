class Solution {
public:
    long long solve(vector<int> &piles,int  mid){
        long long c=0;
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
            long long mid=l+(r-l)/2;
            long long hrs=solve(piles,mid);

            if(hrs>h) l=mid+1;
            else{
                ans=mid;
                r=mid-1;
            }
        }

        return ans;
    }
};
