class Solution {
    private:
    int calc(string s) {
        int cnt = 0;
        for(char c :s) {
            cnt += c-'0';
        }
        return cnt;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;

        for(auto it : bank) {
            int curr = calc(it);
            if(curr == 0) continue;

            ans += curr * prev;
            prev = curr;
        }
        return ans;
    }
};
