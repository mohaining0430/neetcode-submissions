class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (const auto num : nums) {
            int index = num < 0 ? -num : num;
            if (nums[index] < 0)
                return index;
            nums[index] *=-1;
        }
        return -1;
    }
};
