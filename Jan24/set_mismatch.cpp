class Solution {
public:
//O(n) and O(n)
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();

        int expectedSum = n * (n+1) / 2;
        int sum = 0;

        for(int i = 0; i < n; i++) sum += nums[i];

        int repeatedNum = 0;

        unordered_map<int, int> count;
        for(int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        for(auto it : count){
            if(it.second == 2) {
                repeatedNum = it.first;
                break;
            }
        }

        int missingNum = expectedSum - (sum - repeatedNum);

        return {repeatedNum, missingNum};
    }

// O(n) and O(1)
vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        int xorArray = 0;

     
        for (int i = 1; i <= n; i++) {
            xorAll ^= i;
        }

        
        for (int num : nums) {
            xorArray ^= num;
        }

       
        int xorResult = xorArray ^ xorAll;

        
        int rightmostSetBit = xorResult & -xorResult;

        int xorSet = 0;
        int xorNotSet = 0;

        
        for (int i = 1; i <= n; i++) {
            if (i & rightmostSetBit) {
                xorSet ^= i;
            } else {
                xorNotSet ^= i;
            }
        }

        for (int num : nums) {
            if (num & rightmostSetBit) {
                xorSet ^= num;
            } else {
                xorNotSet ^= num;
            }
        }

        
        for (int num : nums) {
            if (num == xorSet) {
                return {xorSet, xorNotSet};
            }
        }

        
        return {xorNotSet, xorSet};
    }
};
