class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int a = 0;
            for(int j = i+1 ; j < arr.size() ; j++){
                a ^= arr[j-1];

                int b = 0;
                for(int k = j ; k < arr.size() ; k++){
                    b ^= arr[k];

                    if(a == b)  ans++;
                }
            }
        }
        return ans;
    }
};
