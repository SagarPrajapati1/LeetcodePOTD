class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& A) {
        double wt = 0, curr = 0;
        for(auto &a : A) {
            curr = max(curr, 1.0*a[0]) + a[1];
            wt += curr - a[0];
        }
        return 1.0 * wt/A.size();
    }
};
