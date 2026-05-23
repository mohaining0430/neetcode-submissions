class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        return n < 0 ? 1 / helper(x, -n) : helper(x, n); 
    }

    double helper(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double val = helper(x, n / 2);
        return n % 2 == 0 ? val * val : val * val * x;
    }
};
