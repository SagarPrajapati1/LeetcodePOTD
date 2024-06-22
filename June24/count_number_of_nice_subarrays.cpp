class Solution {
public:
    int solve(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0) nums[i] = 0; 
            else nums[i] = 1;
        }

        return solve(nums, k) - solve(nums, k-1);

    //    unordered_map<int, int> c({{0, 1}});
    //     int psum = 0, res = 0;
    //     for (int i : nums) {
    //         psum += i;
    //         res += c[psum - k];
    //         c[psum]++;
    //     }
    //     return res;
    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0, odd = 0, count = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                odd++;
                if (odd >= k) {
                    count = 1;
                    while (!(nums[j++] & 1)) count++;
                    total += count;
                }
            } else if (odd >= k) total += count;
        }
        return total;
    }
};
