/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool static compare(Interval &A, Interval &B) {
        return (A.start < B.start);
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int prev = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].end < intervals[prev].end) return false;
            if(intervals[i].start < intervals[prev].end) return false;
            prev++;
        }
        return true;
    }
};
