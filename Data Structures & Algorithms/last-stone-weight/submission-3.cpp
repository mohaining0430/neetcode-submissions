class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, std::less<int>> pq;
        for (auto stone : stones)
            pq.push(stone);
        while (pq.size() >= 2) {
            int p1 = pq.top();
            pq.pop();
            int p2 = pq.top();
            pq.pop();
            if (p1 > p2)
                pq.push(p1 - p2);
        } 
        return pq.empty() ? 0 : pq.top();
    }
};
