class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vc;
        int n = speed.size();
        for(int i=0;i<speed.size();i++) {
            vc.push_back({position[i], speed[i]});
        }
        sort(vc.begin(), vc.end(), [](const auto &a, const auto &b) {
            return a.first > b.first; // Use > for descending
        });
        stack<double>rounds;
        for (int i=0;i<n;i++) {
            double time = (target - vc[i].first) / double(vc[i].second);
            if(rounds.empty() || time > rounds.top())  rounds.push(time);
        }
        return rounds.size();
    }
};
