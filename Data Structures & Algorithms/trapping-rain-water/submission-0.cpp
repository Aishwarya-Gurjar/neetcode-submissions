class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>lMax(n,0);
        vector<int>rMax(n,0);
        if(n<=1)    return 0;
        int ans = 0;
        for(int i=1;i<n;i++) {
            lMax[i] = max(lMax[i-1], height[i-1]);
        }

        for(int i=n-2;i>=0;i--) {
            rMax[i] = max(rMax[i+1], height[i+1]);
        }

        for(int i=1;i<n-1;i++) {
            int water = min(lMax[i], rMax[i]) - height[i];
            if (water>0)    ans+=water;
        }
        return ans;
    }
};
