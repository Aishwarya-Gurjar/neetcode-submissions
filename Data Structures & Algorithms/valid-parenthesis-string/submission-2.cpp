class Solution {
public:
    bool checkValidString(string s) {
        stack<int>braces;
        stack<int>stars;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                braces.push(i);
            }else if(s[i]=='*') {
                stars.push(i);
            }else if(s[i]==')') {
                if(!braces.empty()) braces.pop();
                else if(!stars.empty()) stars.pop();
                else return false;
            }
        }

        while(!braces.empty() && !stars.empty() && braces.top() < stars.top()) {
            braces.pop();
            stars.pop();
        }

        return braces.empty();
    }
};
