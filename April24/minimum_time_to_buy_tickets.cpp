
// Time: O(SUM(A))
// Space: O(1)
// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& A, int k) {
//         int step = 0;
//         while (true) {
//             for (int i = 0; i < A.size(); ++i) {
//                 if (A[i] == 0) continue;
//                 A[i]--;
//                 ++step;
//                 if (A[k] == 0) return step;
//             }
//         }
//     }
// };

// Time: O(N)
// Space: O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& A, int k) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            ans += min(A[k] - (i > k), A[i]);
        }
        return ans;
    }
};
