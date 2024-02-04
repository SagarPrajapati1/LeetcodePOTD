class Solution {
public:
    string minWindow(string str, string t) {
        vector<int> mp(1208, 0);

        for(auto ch : t) mp[ch]++;

        int cnt = t.size();
        int s = 0, e = 0;
        int diff = INT_MAX, h = 0;
        while(e < str.size()) {
            if(mp[str[e++]] --> 0) cnt--;

            while(cnt == 0){
                if(e-s < diff) diff = e-(h=s);
                if(mp[str[s++]]++ == 0) cnt++;
            }
        }

        return diff == INT_MAX ? "" : str.substr(h, diff);
    }
};
