class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector <vector <int > > ans;
        unordered_map<int, int> freq;

        for(auto it : nums) {
            freq[it]++;
        }

        int maxi = 0;
        for(auto it :freq) {
            maxi = max(maxi, it.second);
        }

        for(int i = 0; i < maxi; i++) {
            vector<int> v;

            for(auto &it : freq) {
                if(it.second > 0) {
                    v.push_back(it.first);
                    it.second--;
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
