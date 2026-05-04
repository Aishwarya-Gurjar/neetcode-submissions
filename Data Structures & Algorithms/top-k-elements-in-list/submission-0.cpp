typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pi>pq;
        for(int num: nums){
            mp[num]++;
        }
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        vector<int>res;
        while(!pq.empty() && k-->0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
