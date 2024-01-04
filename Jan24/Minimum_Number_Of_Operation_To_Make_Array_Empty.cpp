class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> count;

        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

      /*
      int ans = 0;
        for(auto [_,it] : count) {
          if(it == 1) return -1;
          ans += ceil((double)it/3);  
        }
        return ans;
      */

        int cnt = 0;
        for(auto it : count) {
            if(it.second == 1) return -1;
            if(it.second % 3 == 0) cnt += it.second/3;
            else if(it.second % 3 == 1) cnt += it.second/3 + 1;
            else if(it.second % 3 == 2) cnt += it.second/3 + 1;
        }
        return cnt;
        
    }
};
