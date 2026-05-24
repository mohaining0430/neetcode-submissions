class Solution {
public:
    // Can skip.
    int reverse(int x) {
        int orig = x;
        x = abs(x);
        string str = to_string(x);
        std::reverse(str.begin(), str.end());
        long long res = stoll(str);
        if (orig < 0)
            res *= -1;
        if (res < -(1LL << 31) || res > (1LL << 31) - 1)
            return 0;
        return static_cast<int>(res);
    }
};
