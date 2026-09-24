class Solution {
public:
    // (05/04/26) Hard to get right.
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int res = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[right]) {
                res = std::min(res, nums[left]);
                break;
            }
            res = std::min(res, nums[mid]);
            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return res;
    }
};
