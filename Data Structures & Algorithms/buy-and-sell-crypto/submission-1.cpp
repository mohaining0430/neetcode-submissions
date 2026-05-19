class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int lowest = INT_MAX;
        for (const auto price : prices) {
            res = max(res, price - lowest);
            if (price < lowest)
                lowest = price;
        }
        return res;
    }
};
