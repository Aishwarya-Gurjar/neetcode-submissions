class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        unordered_map<char,int>mp;
        int n =s.size();
        int maxLen=0;
        while(low<=high && high<n){
            if(mp.find(s[high])!=mp.end() && mp[s[high]] >=low){
                low=mp[s[high]]+1;
            }
            mp[s[high]]=high;
            maxLen=max(maxLen, high-low+1);
            high++;
        }
        return maxLen;
    }
};
