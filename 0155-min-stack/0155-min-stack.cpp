class MinStack {
public:
    stack<int> st;
    stack<int> mnst;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if (mnst.empty())
            mnst.push(value);
        else {
            int temp = mnst.top();
            mnst.push(min(temp, value));
        }
    }
    
    void pop() {
        st.pop();
        mnst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */