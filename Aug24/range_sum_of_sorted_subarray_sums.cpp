class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // step 1 find all the subarray sum

        vector<int> subarray;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i ; j < n; j++){
                sum += nums[j];
                subarray.push_back(sum);
            }
        }
        // step 2 sort that array of subarray sum
        sort(subarray.begin(), subarray.end());
        
        // step 3 get the sdum btw the range
        long long ans = 0;
        int MOD = 1000000007;
        for(int i = left-1; i < right; i++){
            ans = (ans+subarray[i]) % MOD;
        }

        return (int)ans;
    }
};
