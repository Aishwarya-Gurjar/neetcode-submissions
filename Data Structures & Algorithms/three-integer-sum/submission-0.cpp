class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++) {
            int target = -nums[i];
            int low = i+1;
            int high = n-1;
            while(low<high){
                int sum = nums[low]+nums[high];
                if(sum==target){
                    st.insert({nums[i], nums[low], nums[high]});
                    low++;
                }else if(sum>target){
                    high--;
                }else {
                    low++;
                }
            }
        }

        for(auto k : st){
            res.push_back(k);
        }
        return res;
    }

};
