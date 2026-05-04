class Solution {
public:
    bool isPalindrome(string s) {
        string updatedString = prepString(s);
        int low=0;
        int high=updatedString.size()-1;
        while(low<high){
            if(updatedString[low]!=updatedString[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    string prepString(string s) {
        string res = "";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z')  res+=s[i];
            if(s[i]>='0' && s[i]<='9')  res+=s[i];
            if(s[i]>='A' && s[i]<='Z')  res+=('a' + (s[i]-'A'));
        }
        return res;
    }
};
