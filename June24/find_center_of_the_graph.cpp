class Solution {
public:
    // int findCenter(vector<vector<int>>& edges) {
    //     unordered_map<int, int> mp;

    //     for(int i = 0; i < edges.size(); i++) {
    //         mp[edges[i][0]]++;
    //         mp[edges[i][1]]++;
    //     }

    //     int val = INT_MIN;
    //     int ans = 0;
    //     for (auto it : mp) {
    //         if(it.second > val){
    //             val = it.second;
    //             ans = it.first;
    //         }
    //     }
    //     return ans;
    // }
    int findCenter(vector<vector<int>>& e) {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};
