class Solution {
public:
    int pivotInteger(int n) {
        // for(int i = 1; i <= n; i++) {
        //     int prefixSum = (i*(i+1)) / 2;
        //     int suffixSum = (n*(n+1))/2-prefixSum + i;
        //     if(prefixSum == suffixSum) return i;
        // }
        // return -1;

        //  n++;
        // int s = (n*(n+1))/2;
        // int e=0;
        // for(int i=n-1; i>=1; i--){
        //     s -= (i+1);
        //     e += i;
        //     if(s==e)return i;
        //     if(s<e)break;
        // }return -1;

        // using binary search
        int sum = n*(n+1)/2;

        int s = 1;
        int e = n;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            int leftSum = mid * (mid + 1)/2;
            int rightSum = sum - leftSum + mid;

            if(leftSum == rightSum) return mid;

            else if(leftSum < rightSum) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};
