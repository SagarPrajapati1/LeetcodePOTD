class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                nums[i] = '*';
                nums[i - 1] = '*';
            }
        }
        nums.erase(remove(nums.begin(), nums.end(), '*'), nums.end());
        return nums;
    }
};
