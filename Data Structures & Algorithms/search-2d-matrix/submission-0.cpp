class Solution {
public:
    bool solve(int l,int r,int h,vector<vector<int>>& matrix,int target){
        
        while(l<=h){
            int mid=l+(h-l)/2;

            if(matrix[r][mid]==target) return true;

            if(matrix[r][mid]>target) h=mid-1;
            else l=mid+1;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0;
        int n=matrix.size();
        int c=matrix[0].size();

        while(r<n){

            if(target>=matrix[r][0] && target<matrix[r][c-1]){
                return solve(0,r,c-1,matrix,target);
            }
            else{
                r++;
            }
        }

        return false;
    }
};
