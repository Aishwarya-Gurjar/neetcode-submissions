class Solution {
public:
    string minWindow(string source, string target) {
        int low=0;
        int high=0;
        if(source.size()<target.size())   return "";
        unordered_map<char,int>smap;
        unordered_map<char,int>tmap;
        int minWindow=INT_MAX;
        string ans="";

        for(auto k: target)  tmap[k]++;

        while(high<source.size()){
            smap[source[high]]++;
            while(isSubstring(tmap,smap) && low<=high){
                if(minWindow > high-low+1) {
                    minWindow = high-low+1;
                    ans = source.substr(low, high-low+1);
                }
                smap[source[low]]--;
                low++;
            }
            high++;
        }

        return ans;
        
    }

    bool isSubstring(unordered_map<char,int>&smap, unordered_map<char,int>&tmap) {
        for(auto k : smap){
            if(tmap.find(k.first)==tmap.end() || tmap[k.first] < k.second)  return false;
        }
        return true;
    }
};
