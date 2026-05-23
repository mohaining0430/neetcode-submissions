class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (true) {
            if (seen.contains(n))
                return false;
            if (n == 1)
                return true;
            seen.insert(n);
            n = squares(n);
        }
        return false;
    }

    int squares(int n) {
        int res = 0;
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n = n / 10;
        }
        return res;
    }
};
