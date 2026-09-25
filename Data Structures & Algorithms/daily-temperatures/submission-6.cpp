class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<std::pair<int, int>> s;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return res;
    }
};