class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        int n = temp.size();
        vector<int>result(n,0);
        if(n<=1)    return result;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }
            if(!st.empty()) result[i] = st.top().second - i;
            st.push({temp[i], i}); 
        }
        return result;
    }
};
