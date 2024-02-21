class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
         while(n>m)
           n = n & n-1;
        return m&n;

        // 2nd solution
        // return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;

        // 3rd solution
        // bitset<32> b1(m), b2(n), b3(0);
        // for(int i=31; i>=0; i--)
        //     if(b1[i]==b2[i])
        //         b3[i] = b1[i];
        //     else break;
        // return b3.to_ulong();

        // 4th solution
            // int trans = 0;
            // while(m != n) 
            // {
            //     ++ trans;
            //     m >>= 1;
            //     n >>= 1;
            // }
            // return m << trans;

        
    }
};
