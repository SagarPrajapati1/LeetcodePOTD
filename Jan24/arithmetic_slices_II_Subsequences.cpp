class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;

        vector<unordered_map<long long, int>> dp(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++)
             {
                 long long temp = (long long) nums[i]-nums[j];
                 int cnt = dp[j].count(temp)?dp[j][temp]:0;
                 dp[i][temp] += cnt+1;
                 res += cnt;
             }
        }
        return res;
    }
};
