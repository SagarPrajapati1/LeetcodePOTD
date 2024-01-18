class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;

        int cnt1 = 2;
        int cnt2 = 1;
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            cnt = cnt1 + cnt2;
            cnt2 = cnt1;
            cnt1 = cnt;
        }
        return cnt;
    }
};
