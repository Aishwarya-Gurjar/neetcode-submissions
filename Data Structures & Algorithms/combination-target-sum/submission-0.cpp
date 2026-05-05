class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>tp;
        int sum=0;
        helperCombination(nums, target, res, 0, sum, tp);
        return res;
    }

    void helperCombination(vector<int>& nums, int target, vector<vector<int>>&res, int index, int sum, vector<int>&tp) {
        if(sum==target) {
            res.push_back(tp);
            return;
        }
        if(sum > target) return;
        for(int i=index;i<nums.size();i++) {
            tp.push_back(nums[i]);
            sum+=nums[i];
            helperCombination(nums, target, res, i, sum, tp);
            sum-=nums[i];
            tp.pop_back();
        }
    }
};