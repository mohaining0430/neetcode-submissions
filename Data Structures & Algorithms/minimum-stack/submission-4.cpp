class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        data.push(val);
        if (mins.empty() || mins.top() > val)
            mins.push(val);
        else
            mins.push(mins.top());
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop();
            mins.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mins.top();
    }

private:
    stack<int> data;
    stack<int> mins;
};
