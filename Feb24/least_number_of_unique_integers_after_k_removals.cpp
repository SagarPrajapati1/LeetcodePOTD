class Solution {
public:

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }


        vector<pair<int,int>>dp;
        
        for(auto it:mp){
            dp.push_back(it);
        }

        sort(begin(dp),end(dp),[](auto a,auto b){
            return a.second<b.second;
        });

        int count = 0;
        for(auto it: dp){
            if(k>=it.second){
                k-=it.second;
                count++;
            }else{
                break;
            }
        }

        return size(dp) - count;
    }
};
