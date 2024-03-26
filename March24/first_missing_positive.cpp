class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        // int n = arr.size();
        // for (int i = 0; i < n; i++) {
 
        //     // Loop to check boundary
        //     // condition and for swapping
        //     while (arr[i] >= 1 && arr[i] <= n
        //         && arr[i] != arr[arr[i] - 1]) {
        //         swap(arr[i], arr[arr[i] - 1]);
        //     }
        // }

 
        // // Checking any element which
        // // is not equal to i+1
        // for (int i = 0; i < n; i++) {
        //     if (arr[i] != i + 1) {
        //         return i + 1;
        //     }
        // }
    
        // // Nothing is present return last index
        //     return n + 1;
        sort(arr.begin(), arr.end());
        int ans = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == ans) {
                ans++;
            }
        }
        return ans;
        
    }
};
