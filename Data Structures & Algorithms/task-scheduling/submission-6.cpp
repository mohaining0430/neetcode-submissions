class Solution {
public:
    // Can skip!
    int leastInterval(vector<char>& tasks, int n) {
        std::array<int, 26> cnts= {0};
        for (const auto c : tasks)
            cnts[c - 'A']++;
        priority_queue<int, vector<int>, std::less<int>> pq;
        for (const auto cnt : cnts)
            if (cnt > 0)
                pq.push(cnt);

        int time = 0;
        queue<pair<int, int>> q;
        // Note the code symmetry in the while loop: 
        // pq pops, pushes into q; 
        // p pops and pushes into pq.
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int cnt = pq.top() - 1;
                if (cnt > 0)
                    q.push(std::make_pair(cnt, time + n));
                pq.pop();
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};