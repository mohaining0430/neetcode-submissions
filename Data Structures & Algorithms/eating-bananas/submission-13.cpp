class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (const auto& pile : piles)
            maxPile = std::max(maxPile, pile);  
        int left = 1, right = maxPile;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (hours(piles, mid) > h)
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }

    int hours(vector<int>& piles, int k) {
        int res = 0;
        for (const auto pile : piles)
            res += (pile + k - 1) / k;
        return res;
    }
};
