// find the exact match
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return (left >= 1 && nums[left - 1] == target) ? left - 1 : -1;
    }
};

/*
// find first element that is > target
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left >= 1 && nums[left - 1] == target ? left - 1 : -1;
    }
};

// find first element that is >= target
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else 
                right = mid;
        }
        return left < nums.size() && nums[left] == target ? left : -1;
    }
};
*/