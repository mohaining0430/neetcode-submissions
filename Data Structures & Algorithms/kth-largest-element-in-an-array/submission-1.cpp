class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (const auto num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
