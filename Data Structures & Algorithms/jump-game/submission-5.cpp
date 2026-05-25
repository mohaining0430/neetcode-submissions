class Solution {
public:
    // Greedy
    // Can skip. Instead, do Jump Game II
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= goal)
                goal = i;
        }
        return goal == 0;
    }
};

/*
// DFS
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }

    bool dfs(vector<int>& nums, int index) {
        if (index == nums.size() - 1) // you just have to reach the last step.
            return true;
        for (int i = 1; i <= nums[index]; ++i) {
            if (dfs(nums, index + i))
                return true;
        }
        return false;
    }
};
*/
