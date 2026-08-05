class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int left = 0, right = heights.size() - 1;
        while (left < right) {
            int cur = (right - left) * min(heights[left], heights[right]);
            res = max(res, cur);
            if (heights[left] < heights[right])
                left++;
            else if (heights[left] > heights[right])
                right--;
            else {
                left++;
                right--;
            }
        }
        return res;
    }
};
