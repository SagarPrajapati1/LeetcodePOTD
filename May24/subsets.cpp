class Solution {
public:

    void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }

        // pick the element
        temp.push_back(nums[i]);
        solve(i+1, nums, temp, ans);
        temp.pop_back();

        // not pick the element
        solve(i+1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, temp, ans);
        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}}; // Add the empty subset
        for (int num : nums) {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }
        return result;
    }
};
