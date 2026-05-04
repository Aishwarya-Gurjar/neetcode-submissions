class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        long long ans = -1;

        while(low<=high) {
            int mid = low + (high-low)/2;
            long long reqTime = findTime(piles, mid);
            if ( reqTime <= h) {
                ans = mid;
                high= mid-1;
            }else {
                low = mid+1;
            }
        }
        return ans;
    }

    long long findTime(vector<int>&piles, int capacity) {
        long long time = 0;
        for(int i=0;i<piles.size();i++) {
            long long tp = ceil(piles[i]/ (double) capacity);
            time+=tp;
        }
        return time;
    }
};
