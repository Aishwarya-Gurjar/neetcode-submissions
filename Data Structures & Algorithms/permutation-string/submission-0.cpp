class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>s1map(26,0);
        vector<int>s2map(26,0);
        if(s1.size()>s2.size()) return false;
        if(s1.size()==0)    return true;

        for(int i=0;i<s1.size();i++){
            s1map[s1[i]-'a']++;
        }
        int high = 0;
        for(high=0;high<s1.size();high++){
            s2map[s2[high]-'a']++;
        }
        int low=0;
        while(high<s2.size()) {
            if(isEqual(s1map, s2map))   return true;
            s2map[s2[low]-'a']--;
            s2map[s2[high]-'a']++;
            low++;
            high++;
        }
        if(isEqual(s1map, s2map))   return true;
        return false;
    }

    bool isEqual(vector<int>&s1map, vector<int>&s2map){
        for(int i=0;i<26;i++){
            if(s1map[i]!=s2map[i])  return false;
        }
        return true;
    }
};
