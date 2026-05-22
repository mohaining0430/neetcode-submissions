class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (const auto num : nums) {
            pq.push(num);
            if (pq.size() > size)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int size;
};
