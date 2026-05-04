class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>mp;
        mp['1']=""; mp['2']="abc"; mp['3']="def";
        mp['4']="ghi"; mp['5']="jkl"; mp['6']="mno";
        mp['7']="pqrs"; mp['8']="tuv"; mp['9']="wxyz";
        mp['0']="+";

        vector<string>prev;
        if(digits.size()==0)    return prev;
        for(auto k : mp[digits[0]]){
            string s1;
            prev.push_back(s1+k);
        }
        if(digits.size()==1){
            return prev;
        }
        for(int i=1;i<digits.size();i++){
            vector<string>res;
            for(auto j : prev){
                string tp = j;
                for(auto k : mp[digits[i]]) {
                    tp.push_back(k);
                    res.push_back(tp);
                    tp.pop_back();
                }
            }
            prev = res;
        }

        return prev;
    }
};
