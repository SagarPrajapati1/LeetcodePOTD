class Solution {
public:
    void solve(int index, string &s, vector<string> &temp, vector<vector<string>>& subset){
        if(index == s.size()) {
            subset.push_back(temp);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                solve(i+1, s, temp, subset);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        // find out all subsets
        vector<vector<string>> subset;
        vector<string> temp;
        solve(0, s, temp, subset);  

        return subset;
    }
};
