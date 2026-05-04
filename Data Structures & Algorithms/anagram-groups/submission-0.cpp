class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(auto k : strs) {
            string tp = k;
            sort(tp.begin(), tp.end());
            mp[tp].push_back(k);
        }
        vector<vector<string>>res;
        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};
