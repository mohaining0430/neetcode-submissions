class Solution {
public:
    // Can skip!
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
/*
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;
        for (const auto triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] 
                || triplet[2] > target[2])
                continue;
            for (int i = 0; i < 3; ++i)
                if (triplet[i] == target[i])
                    good.insert(i);
            if (good.size() == 3)
                return true;
        }
        return false;
    }
};
*/