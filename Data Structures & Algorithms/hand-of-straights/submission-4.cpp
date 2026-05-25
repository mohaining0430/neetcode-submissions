class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Instead of sorting, you can also use a prirority queue and
        // pick the smallest number every time.
        std::sort(hand.begin(), hand.end());

        unordered_map<int, int> count;
        for (const auto num : hand)
            count[num]++;

        for (const auto num : hand) {
            if (count[num] <= 0)
                continue;
            for (int i = num; i < num + groupSize; ++i) {
                if (count[i] <= 0)
                    return false;
                count[i]--;
            }
        }
        return true;
    }
};