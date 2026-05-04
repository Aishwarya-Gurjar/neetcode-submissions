class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mid;
        int low =0, high=m-1;
        while(low<=high){
            mid = low+(high-low)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1]>=target){
                return binarySearch(matrix[mid], target);
            }
            if(matrix[mid][n-1]<target){
                low= mid+1;
            }else {
                high = mid-1;
            }
        }
        return false;
    }

    bool binarySearch(vector<int>& nums, int target) {
        int low = 0;
        int high= nums.size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid]==target)   return true;
            if(nums[mid]<target) {
                low = mid+1;
            }else {
                high=mid-1;
            }
        }
        return false;
    }
};
