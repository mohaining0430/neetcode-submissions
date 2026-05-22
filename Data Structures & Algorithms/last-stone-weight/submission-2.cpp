class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, std::less<int>> pq;
        for (const auto stone : stones)
            pq.push(stone);
        
        while (pq.size() >= 2) {
            int heavy1 = pq.top();
            pq.pop();
            int heavy2 = pq.top();
            pq.pop();
            if (heavy1 > heavy2) {
                heavy1 -= heavy2;
                pq.push(heavy1);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
