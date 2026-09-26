class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i <= n; ++i) 
            res ^= i;
        for (auto num : nums)
            res ^= num;
        return res;
    }
};
