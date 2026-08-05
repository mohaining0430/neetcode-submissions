class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (data.empty())
            mins.push(val);
        else 
            mins.push(min(val, mins.top()));
        data.push(val);
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
