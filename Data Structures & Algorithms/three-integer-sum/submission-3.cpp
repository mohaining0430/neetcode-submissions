/*Need more practice*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i <= nums.size() - 3; ++i) {
            if (i >= 1) {
                while (i < nums.size() && nums[i] == nums[i - 1])
                    i++;
                if (i > nums.size() - 3)
                    break;
            }
            int target =  0 - nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    vec.push_back(nums[k]);
                    res.push_back(vec);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;                   
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }  
        return res;      
    }
};
