class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low =0;
        int high = heights.size()-1;
        int maxArea = 0;
        while(low<high){
            int minH = min(heights[low], heights[high]);
            maxArea= max(maxArea, minH*(high-low));
            if(heights[low]==minH){
                low++;
            }else {
                high--;
            }
        }
        return maxArea;
    }
};
