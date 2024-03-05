class Solution {
public:
    int minimumLength(string s) {
        
        // 1st case
        if(s.length() == 0)return 0;

        int n = s.length();
        
        // 2nd case
        if(n == 1) return 1;

        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == s[j]){
            
            char ch = s[i];
            while(i <= j && s[i] == ch) i++; 
            while(i <= j && s[j] == ch) j--;
        }
        return j-i+1;
    }
};
