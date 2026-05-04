class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid]==target)   return mid;
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target<nums[mid]) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }else if(nums[mid]<= nums[high]) {
                if(target > nums[mid] && target <=nums[high]) {
                    low = mid+1;
                }else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
