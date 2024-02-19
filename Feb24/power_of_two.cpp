class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n == 1 || n == 2) return true;
        // if(n % 2 != 0) return false;

        // for(int i = 2; pow(2, i) <= n; i++){
        //     if(pow(2, i) == n) return true;
        // }
        // return false;

        // second solution
        if(n == 0) return false;

        while(n % 2 == 0) n /= 2;
        return n == 1;

        // third solution
        // return ((n & (n-1)) == 0);

        // fourt solution 
         if(n <= 0) return false;
        return ceil(log2(n)) == floor(log2(n));

        // fifth solution
        /*
        if(n<0)return false;
        
        int bits=__builtin_popcount(n);
        
        if(bits==1)
            return true;
        return false;
        */
    }
};
