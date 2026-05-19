class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int lowestPrice = INT_MAX;
        for (const auto price : prices) {
            res = std::max(price - lowestPrice, res);
            lowestPrice = std::min(lowestPrice, price);
        }
        return res;
    }
};
