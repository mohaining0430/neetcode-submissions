class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<std::pair<int, int>> s;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            auto temperature = temperatures[i];
            while (!s.empty() && s.top().first < temperature) {
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperature, i});
        }
        return res;
    }
};
