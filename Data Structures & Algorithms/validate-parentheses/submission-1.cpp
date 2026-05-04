class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(isClosing(s[i])) {
                if(st.empty() || !isMatching(st.top(), s[i]))    return false;
                st.pop();
            }else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }

    bool isMatching(char x, char y) {
        return ((x=='{' && y=='}') || (x=='[' && y==']') || (x=='(' && y==')'));
    }

    bool isClosing(char x) {
        return (x=='}' || x==']' || x==')');
    }
};
