class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < values.size(); i++) {
            mx = max(mx, values[i] + ans);

            ans = max(ans, values[i]) - 1;

        }
        return mx;
    }
};
