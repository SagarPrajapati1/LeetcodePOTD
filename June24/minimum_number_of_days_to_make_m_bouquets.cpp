// TLE Solution

class Solution {
public:
    bool possible(vector<int>& bloomDay, int ind, int m, int k) {

        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= ind) cnt++;
            else {
                ans += (cnt/k);
                cnt = 0;
            }
        }
        ans += cnt/k;
        if(ans >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(m*k > n) return -1;

        auto mini = min_element(bloomDay.begin(), bloomDay.end());
        auto maxi = max_element(bloomDay.begin(), bloomDay.end());
        
        int miniEle = *mini;
        int maxiEle = *maxi;

        for(int i = miniEle; i <= maxiEle; i++) {
            if(possible(bloomDay, i, m, k)) return i;
        }
        return -1;
    }
};


class Solution {
public:
bool possible(vector<int>& bloomDay, int ind, int m, int k) {

        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= ind) cnt++;
            else {
                ans += (cnt/k);
                cnt = 0;
            }
        }
        ans += cnt/k;
        if(ans >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int mini =  INT_MAX; //*min_element(bloomDay.begin(), bloomDay.end());
        int maxi = INT_MIN; //*max_element(bloomDay.begin(), bloomDay.end());

        for(int i = 0; i < n; i++){
            mini = min(bloomDay[i], mini);
            maxi = max(bloomDay[i], maxi);
        }

        int low = mini;
        int high = maxi;
        int ans = high;

        if((1LL*m*1LL*k) > n) return -1;

        while(low <= high) {

            int mid = low + (high - low)/2;
            if(possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else{ 
                low = mid + 1;
            }
        }

        return low;
    }
};


