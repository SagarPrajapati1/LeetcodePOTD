class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();

        vector<int> dp(k);

        for(int i = 1; i <= n; i++) {
            int maxi = 0;
            int ans = 0;

            for(int j = 1; j <= k && i-j >= 0; j++) {
                maxi = max(maxi, arr[i-j]);

                ans = max(ans, dp[(i-j) % k] + maxi * j);
            }

            dp[i%k] = ans;
        }

        return dp[n % k];
    }
};
