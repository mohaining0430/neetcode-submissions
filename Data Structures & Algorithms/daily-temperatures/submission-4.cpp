class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!s.empty()) {
                if (temperatures[i] > s.top().second) {
                    res[s.top().first] = i - s.top().first;
                    s.pop();
                } else {
                    break;
                }
            }
            s.push({i, temperatures[i]});
        }
        return res;
    }
};
