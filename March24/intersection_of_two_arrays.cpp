class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        unordered_set<int> st;
            while(i < nums1.size() && j < nums2.size()) {
                if(nums1[i] == nums2[j]) {
                    ans.push_back(nums1[i]);
                    i++; j++;
                }
                else if(nums1[i] < nums2[j]) i++;
                else if(nums1[i] > nums2[j]) j++;
            }

            // for(auto it: st) ans.push_back(it);
             ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
}
