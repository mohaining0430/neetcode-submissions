class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<point, vector<point>, std::greater<point>> pq;
        vector<vector<int>> res;
        for (const auto p : points) {
            point cur(p[0], p[1]);
            pq.push(cur);
        }
        while (k-- > 0) {
            point cur = pq.top();
            pq.pop();
            vector<int> vec;
            vec.push_back(cur.x);
            vec.push_back(cur.y);
            res.push_back(vec);
        }
        return res;
    }

private:
    struct point {
        int x;
        int y;
        point(int x_axis, int y_axis) : x(x_axis), y(y_axis) {}
        bool operator > (const point& other) const {
            return x * x + y * y > other.x * other.x + other.y * other.y;
        }
    };
};
