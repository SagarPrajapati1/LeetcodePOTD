class Solution {
public:
    void solve(string s, int i, int j){
        

        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--; j++; cnt++;
        }
       
    }
    int cnt = 0;

    int countSubstrings(string s) {
        
        if(s.length() == 0) return 0;

        for(int i = 0; i < s.length(); i++) {                
                solve(s, i, i);
                solve(s, i, i+1);
        }

        return cnt;
    }
};
