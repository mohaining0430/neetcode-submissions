class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> valid;
        for (auto triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] ||
                triplet[2] > target[2])
                continue;
            valid.push_back(triplet);
        }

        int max0 = INT_MIN, max1 = INT_MIN, max2 = INT_MIN;
        for (const auto v : valid) {
            max0 = max(max0, v[0]);
            max1 = max(max1, v[1]);
            max2 = max(max2, v[2]);
        }
        return max0 == target[0] && max1 == target[1] && max2 == target[2];
    }
};
