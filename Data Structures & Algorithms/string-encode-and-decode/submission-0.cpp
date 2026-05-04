class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(string s : strs) {
            int len = s.length();
            res+=to_string(len);
            res+='#';
            res+=s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int i =0;
        while(i<s.size()) {
            if(s[i]>='0' && s[i]<='9'){
                int j=i;
                string num = "";
                while(j<s.size() && s[j]!='#') {
                    num+=s[j];
                    j++;
                }
                int len  = stoi(num);
                res.push_back(s.substr(j+1, len));
                i = j+1+len; 
            }
        }
        return res;
    }
};
