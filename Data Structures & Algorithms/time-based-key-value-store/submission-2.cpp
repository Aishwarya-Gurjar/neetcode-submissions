class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())  return "";
        vector<pair<int, string>> vc = mp[key];
        auto it = upper_bound(vc.begin(), vc.end(), timestamp, 
        [](int val, const std::pair<int, std::string>& p){
            return val < p.first; // Compare the single value with the pair's first element
        });
        if(it==vc.begin())    return "";
        return (--it)->second;
    }
};
