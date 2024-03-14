class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
        
    }
    int solve( vector<int> &nums, int goal){
        int sum = 0;
        if(goal < 0) return 0;

        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            goal -= nums[j];
            while(goal < 0)
            {
                goal += nums[i++]; 
            }
            sum += j-i+1;
        }
        return sum;
    }
};
