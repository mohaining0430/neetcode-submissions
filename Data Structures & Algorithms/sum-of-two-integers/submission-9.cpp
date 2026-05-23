class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for (int i = 0; i < 32; ++i) {
            int a_bit = a >> i & 0x1;
            int b_bit = b >> i & 0x1;
            res |= ((a_bit + b_bit + carry) % 2) << i;
            carry = (a_bit + b_bit + carry) / 2;
        }
        return res;
    }
};
