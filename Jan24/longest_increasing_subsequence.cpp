class Solution {
    // int solve(int ind, int prev_ind, vector<int> nums, int n,  vector<vector<int>> &dp) {
    
//     //Recursive Solution
    //     // // base case
    //     // if(ind == n) return 0;
    //     // if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

    //     // // not pick

    //     // int length = solve(ind+1, prev_ind, nums, n, dp);

    //     // // pick

    //     // if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
    //     //     length = max(length, solve(ind+1, ind, nums, n, dp) + 1);
    //     // }
    //     // return dp[ind][prev_ind+1] = length;
    // }
public:
    int lengthOfLIS(vector<int>& nums) {

        int n =  nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));

        // return solve(0, -1, nums, n, dp);

        vector<int> temp;
        temp.push_back(nums[0]);

        int len = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};
