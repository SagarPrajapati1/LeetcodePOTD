class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int find = 0;
         

        while(true){
            slow = nums[slow];
            find = nums[find];
            if(find == slow) {
                break;
            }
        }

        return slow;
    }

};
