class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            res.push_back((carry + digits[i]) % 10);
            carry = (carry + digits[i]) / 10;
        }
        if (carry)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
