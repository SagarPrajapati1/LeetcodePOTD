class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int> mp;
        for(int i = 0; i < arr.size(); i++){
            string str = arr[i];
            mp[str]++;
        }
        for (auto &s : arr)
        if (mp[s] == 1 && --k == 0)
            return s;
    return "";
    }
};
