class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while(i < n1 && j < n2){
            int val1 = nums1[i];
            int val2 = nums2[j];

            if(val1 == val2) return val1;
            else if(val1 < val2) i++;
            else if(val1 > val2) j++;
        }
        return -1;
    }
};
