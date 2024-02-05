class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<int, int> mp;
        for(char ch : s){
            mp[ch] += 1;
        }

        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};
