class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        auto cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (cur[1] < intervals[i][0]) {
                res.push_back(cur);
                cur = intervals[i];
            } else {
                cur[0] = min(cur[0], intervals[i][0]);
                cur[1] = max(cur[1], intervals[i][1]);                
            }
        }
        res.push_back(cur);
        return res;
    }
};
