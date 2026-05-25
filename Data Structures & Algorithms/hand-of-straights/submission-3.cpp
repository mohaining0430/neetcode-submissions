class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> m;
        for (const auto h : hand) 
            m[h]++;
        for (const auto h : hand) {
            if (m[h] <= 0)
                continue;
            for (int i = 0; i < groupSize; ++i) {
                if (m[h + i] <= 0)
                    return false;
                m[h + i]--;
            }
        }
        return true;
    }
};
