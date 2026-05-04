class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int>res;
        int low =0, high= num.size()-1;
        while(low<high){
            int sum = num[low]+num[high];
            if(sum==target){
                res.push_back(low+1);
                res.push_back(high+1);
                return res;
            }else if(sum > target){
                high--;
            }else {
                low++;
            }
        }
        return res;
    }
};
