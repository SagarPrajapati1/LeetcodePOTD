class Solution {
public:

    // memoization
    // int solve(vector<int> &nums, int i, vector<int> &dp) {
        
    //     // base case
    //     if(i >= nums.size()) return 0;
        
    //     // check if exist
    //     if(dp[i] != -1) return dp[i];

    //     return dp[i] = max(solve(nums, i+1, dp), solve(nums, i+2, dp) + nums[i]);
    // }
    int rob(vector<int>& nums) {
        // memoization
        // vector<int> dp(nums.size() + 1, -1);
        // return solve(nums, 0, dp);
        // tabulation
        // if(nums.size()==1) return nums[0];
    
        // vector<int> dp(nums.size());
        
        // dp[0] = nums[0];
        // dp[1] = max(dp[0], nums[1]);
        
        // for(int i=2; i<nums.size(); i++)
        // {
        //     dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        // }
        // return dp[nums.size()-1];

        // space optimization
        if(nums.size()==1) return nums[0];

        int num1 = max(nums[0], nums[1]);
        int num2 = nums[0];
        
        int curr;

        for(int i =2; i < nums.size(); i++) {
            curr = max(num1, num2 + nums[i]);
            num2 = num1;
            num1 = curr;
        }
        return num1;
        
    }
};
