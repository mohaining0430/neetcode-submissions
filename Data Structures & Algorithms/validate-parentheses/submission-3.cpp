class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (const auto c : s) {
            if (c == '[' || c == '(' || c == '{') {
                stack.push(c);
            } else if (c == ']') {
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else 
                    return false;
            } else if (c == ')') {
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else 
                    return false;
            } else if (c == '}') {
                if (!stack.empty() && stack.top() == '{')
                    stack.pop();
                else 
                    return false;
            }
        }
        return stack.empty();
    }
};
