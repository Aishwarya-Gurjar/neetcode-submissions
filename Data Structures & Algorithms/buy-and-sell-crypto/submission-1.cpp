class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int rMax=prices[n-1];
        int maxProfit=0;
        for(int i=n-2;i>=0;i--) {
            maxProfit = max(maxProfit, rMax-prices[i]);
            rMax = max(rMax, prices[i]);
        }
        return maxProfit;
    }
};
