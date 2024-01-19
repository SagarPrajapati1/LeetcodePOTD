class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        // for (auto i = 1; i < A.size(); ++i)
        //     for (auto j = 0; j < A.size(); ++j)
        //         A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)] });
        
        // return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));

        int row = A.size();
        int col = A[0].size();

        int ans = INT_MAX;
        vector<vector<int>> dp(row+1, vector<int> (col+1, INT_MAX));
        for(int i = 0; i < col; i++) {
            ans = min(ans, solve(A, row-1, i, dp));
        }
        return ans;

    }


    int solve(vector<vector<int>>& A, int r, int c, vector<vector<int>>& dp) {
        if(r == 0 && c >= 0 && c < A[0].size()) return A[r][c];
        if(c < 0 || c >= A[0].size()) return INT_MAX;
        
        if(dp[r][c] != INT_MAX) return dp[r][c];
        return dp[r][c] =  A[r][c] + min(min(solve(A, r-1, c-1, dp), solve(A, r-1, c, dp)), solve(A, r-1, c+1, dp));
    }
};
