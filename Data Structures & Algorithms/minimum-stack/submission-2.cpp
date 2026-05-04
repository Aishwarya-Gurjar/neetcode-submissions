class MinStack {
    private:
        stack<int>st;
        stack<int>minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);    
        if(minStack.empty() || val<=minStack.top())    minStack.push(val);
    }
    
    void pop() {
        if(getMin()==st.top())  minStack.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
