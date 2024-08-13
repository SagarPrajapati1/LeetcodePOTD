class Solution {
public:
    void solve(vector<int>& arr, int i, int k, vector<int>& temp,
               vector<vector<int>>& ans) {

        if (k == 0) {
            ans.push_back(temp);
            return;
        }

        for (int ind = i; ind < arr.size(); ind++) {
            if (arr[ind] > k)
                break;

            if (ind > i && arr[ind] == arr[ind - 1])
                continue;
            temp.push_back(arr[ind]);
            solve(arr, ind + 1, k - arr[ind], temp, ans);
            temp.pop_back();
        }

        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, temp, ans);
        return ans;
    }
};
