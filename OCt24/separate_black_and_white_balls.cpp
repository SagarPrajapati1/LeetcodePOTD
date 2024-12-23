class Solution {
public:
    long long minimumSteps(const string &s) {
    long long res = 0;
    for (int i = 0, cnt = 0; i < s.size(); ++i) {
        if (s[i] == '1')
            ++cnt;
        else
            res += cnt;
    }
    return res;
    }
};
