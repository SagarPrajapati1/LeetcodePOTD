class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > 0 && std::binary_search(nums.begin(), nums.end(), -nums[i])) {
                return nums[i];
            }
        }
        return -1;  // If no such pair found
    }
};

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int maxK = std::numeric_limits<int>::min();
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == 0) {
                maxK = std::max(maxK, nums[right]);
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
        return maxK != std::numeric_limits<int>::min() ? maxK : -1;  // If no such pair found
    }
};
