class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()), suffix(nums.size());
        int cur = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] = cur;
            cur *= nums[i];
        }

        cur = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            suffix[i] = cur;
            cur *= nums[i];
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            res.push_back(prefix[i] * suffix[i]);
        }
        return res;
    }
};
