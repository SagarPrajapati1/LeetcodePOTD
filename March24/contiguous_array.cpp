class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp; 

        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = (nums[i] == 0) ? -1 : 1 ;
        }
        int ind = 0;
        int len = 0;

        for(int i = 0; i < nums.size(); i++) {
            ans += nums[i];

            if(ans == 0){
                len = i+1;
                ind = i;
            }
            if(mp.find(ans) != mp.end()){
                if(len < i - mp[ans]){
                    len = i-mp[ans];
                    ind = i;
                }
            }
            else mp[ans] = i;
        }
        return len;

        return ans;
    }
};
