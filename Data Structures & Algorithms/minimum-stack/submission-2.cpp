class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        data.push(val);
        int min = mins.empty() ? val : std::min(val, mins.top());
        mins.push(min);
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
