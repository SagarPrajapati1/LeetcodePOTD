class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 1;
        int arr[101] = {0};
    
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        } 

        // for (auto i : arr) cout << i<< " ";
        // cout << endl;

        int maxi = *max_element(arr, arr+100);
        
        int cnt = 0;
        // cout << maxi << endl;
        for(int i = 0; i < 101; i++){
            if(arr[i] == maxi) cnt += arr[i];
            // cout << arr[i] << " " << cnt << endl;
        }
        return cnt;
