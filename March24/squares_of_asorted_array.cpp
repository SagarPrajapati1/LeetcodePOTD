class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // for(int i = 0; i < nums.size(); i++) {
        //     nums[i] = nums[i] * nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // return nums;
        int l = 0;
        int r = nums.size() - 1;
        vector<int> ans(nums.size(), 0);


        for(int i = nums.size() - 1; i >= 0; i--) 
        {
            if(abs(nums[l]) > abs(nums[r]))
            {
                ans[i] = nums[l] * nums[l++];
            } 
            else {
                ans[i] = nums[r] * nums[r--];
            }
        }
        return ans;
    }
};
