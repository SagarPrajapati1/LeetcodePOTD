class Solution {
private:
    int _beautifulSubsets(vector<int>& nums, int k, unordered_map<int, int>& freq, int i) {
        if (i == nums.size()) { // base case
            return 1;
        }
        int result = _beautifulSubsets(nums, k, freq, i + 1); // nums[i] not taken
        if (!freq[nums[i] - k] && !freq[nums[i] + k]) { // check if we can take nums[i]
            freq[nums[i]]++;
            result += _beautifulSubsets(nums, k, freq, i + 1); // nums[i] taken
            freq[nums[i]]--;
        }
        return result;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        return _beautifulSubsets(nums, k, freq, 0) - 1; // -1 for empty subset
    }
};


class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int n = fr.second.size();
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            vector<int> count(n + 1);
            count[n] = 1;
            for (int i = n - 1; i >= 0; i--) {
                int skip = count[i + 1];
                int take = (1 << s[i].second) - 1;
                if (i + 1 < n && s[i + 1].first - s[i].first == k) {
                    take *= count[i + 2];
                } else {
                    take *= count[i + 1];
                }
                count[i] = skip + take;
            }
            result *= count[0];
        }
        return result - 1;
    }
};


class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int n = fr.second.size(), curr, next1 = 1, next2;
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            for (int i = n - 1; i >= 0; i--) {
                int skip = next1;
                int take = (1 << s[i].second) - 1;
                if (i + 1 < n && s[i + 1].first - s[i].first == k) {
                    take *= next2;
                } else {
                    take *= next1;
                }
                curr = skip + take;
                next2 = next1; next1 = curr;
            }
            result *= curr;
        }
        return result - 1;
    }
};


class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int prevNum = -k, prev2, prev1 = 1, curr;
            for (auto& [num, f]: fr.second) {
                int skip = prev1;
                int take = ((1 << f) - 1) * (num - prevNum == k ? prev2 : prev1);
                curr = skip + take;
                prev2 = prev1; prev1 = curr;
                prevNum = num;
            }
            result *= curr;
        }
        return result - 1;
    }
};
