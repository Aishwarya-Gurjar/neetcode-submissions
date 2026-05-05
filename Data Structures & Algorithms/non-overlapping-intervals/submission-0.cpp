class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        res.push_back(intervals[0]);
        int count =0;
        for(int i=1;i<n;i++) {
            if(res.back()[1] > intervals[i][0]) {
                count++;
                res.back()[0] = max(res.back()[0], intervals[i][0]);
                res.back()[1] = min(res.back()[1], intervals[i][1]);
            }else {
                res.push_back(intervals[i]);
            }
        }
        return count;
    }
};
