class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int num = 1; num <= n; ++num) {
            int cur = num;
            int cnt = 0;
            while (cur) {
                if (cur & 0x1)
                    cnt++;
                cur = cur >> 1;
            }
            res[num] = cnt;
        }
        return res;
    }
};
