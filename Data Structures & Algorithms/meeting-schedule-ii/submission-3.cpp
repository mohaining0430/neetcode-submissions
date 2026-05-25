/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    // Can skip.
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        for (const auto& interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0, count = 0;
        int s = 0, e = 0;
        while (s < start.size()) {
            if (start[s] < end[e]) {
                count++;
                s++;
            } else {
                count--;
                e++;
            }
            res = max(res, count);
        }
        return res;
    }
};
