class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        for (i = 0; i < intervals.size(); ++i) {
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                break;
            } else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        if (i == intervals.size())
            res.push_back(newInterval);
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};