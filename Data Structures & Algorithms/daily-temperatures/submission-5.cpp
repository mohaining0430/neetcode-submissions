class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > stack.top().first) {
                res[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push({temperatures[i], i});
        }
        // Technically not needed since res is initialized to all zeros.
        while (!stack.empty()) {
            res[stack.top().second] = 0;
            stack.pop();
        }
        return res;
    }
};