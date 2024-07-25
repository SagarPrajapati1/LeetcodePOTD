class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // stable_sort(nums.begin(), nums.end());
        return nums;
    }
};
