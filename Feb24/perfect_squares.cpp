class Solution {
public:
    // fourth solution
    int solve(int n) {
        // if(n == 0) return 0;
        // if(n <= 3) return n;

        if(ceil(sqrt(n)) == floor(sqrt(n))) return 1;

        while(n % 4 == 0) n /= 4;
        if(n % 8 == 7) return 4;


        for(int i = 1; i*i <= n; i++){
            int base = sqrt(n-i*i);

            if(base * base == (n - i*i)) return 2;
        }
        return 3;

    }
    /*
    // third solution using tabulation

    int solve(int n, vector<int> &dp){
        
        //base case
        if(n == 0) return 0;
    
        for(int i = 1; i <= n; i++){

            dp[i] = i;
            for(int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i], 1+dp[i- j*j]);
        }
        return dp[n];
    }
    */

    /*
    // second solution using memoization
    int solve(int n, vector<int> &dp) {
        if(n <= 3) return n;
        if(dp[n] != -1) return dp[n];

        int ans = n;
        for(int i = 1; i * i <= n; ++i){
            ans = min(ans, 1 + solve(n-i*i, dp));
        }

        return dp[n] = ans;
    }
    */

    /*
    // first solution using recursion
    int solve(int n) {
        if(n <= 3) return n;
        int ans = n;
        for(int i = 1; i*i <= n; i++) {
            ans = min(ans, 1 + solve(n-i*i));
        }
        return ans;
    }
    */

    int numSquares(int n) {

        vector<int> dp(n+1, -1);
        dp[0] = 0;
        // return solve(n, dp);
        return solve(n);

    }
};
