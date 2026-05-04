class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*") {
                applyOperator(st, tokens[i][0]);
            }else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }

    void applyOperator(stack<int>&st, char operation) {
        int x = st.top();   st.pop();
        int y = st.top(); st.pop();
        switch(operation) {
            case '+':
                st.push(y+x);
                break;
            case '-':
                st.push(y-x);
                break;
            case '/':
                st.push(y/x);
                break;
            case '*':
                st.push(y*x);
                break;
            default:
                break;
        }
    }
};
