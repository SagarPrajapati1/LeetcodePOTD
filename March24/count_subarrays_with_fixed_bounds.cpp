class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int mini = -1, maxi = -1;
        
        int start = 0;
        for(int i = 0; i < nums.size(); i++){
            if(minK > nums[i] || nums[i] > maxK) mini = -1, maxi = -1, start = i+1;
            if(nums[i] == minK) mini = i;
            if(nums[i] == maxK) maxi = i;
            ans += max(0, min(mini, maxi) - start + 1);
        }
        return ans;
    }
};
