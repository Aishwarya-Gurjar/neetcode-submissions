class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        map<int,unordered_set<int>>mp;
        int n = nums.size();
        for(int i=0;i<min(n,k);i++) {
            mp[nums[i]].insert(i);
        }
        for(int i=k;i<n;i++) {
            result.push_back(mp.rbegin()->first);
            mp[nums[i-k]].erase(i-k);
            if(mp[nums[i-k]].size()==0) {
                mp.erase(nums[i-k]);
            }
            mp[nums[i]].insert(i);
        }
        result.push_back(mp.rbegin()->first);
        return result;
    }
};
