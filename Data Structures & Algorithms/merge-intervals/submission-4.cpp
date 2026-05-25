class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        vector<int> cur = intervals[0];
        int i = 0;
        for (i = 1; i < intervals.size(); ++i) {
            auto& interval = intervals[i];
            if (cur[1] < interval[0]) {
                res.push_back(cur);
                cur = interval;
            } else if (cur[0] > interval[1]) {
                res.push_back(interval);
            } else {
                cur[0] = min(cur[0], interval[0]);
                cur[1] = max(cur[1], interval[1]);
            }
        }
        if (i == intervals.size())
            res.push_back(cur);
        return res;
    }
};
