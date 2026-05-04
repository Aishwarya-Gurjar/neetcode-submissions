class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>num_set;
        for(int k : nums) {
            if(num_set.find(k)!=num_set.end())  return true;
            num_set.insert(k);
        }
        return false;
    }
};