class Solution {
public:
    int scoreOfString(string s) {
        
        int sum = 0;

        for(int i = 0; i < s.length()-1; i++){
            int val1 = s[i]-'a';
            int val2 = s[i+1] - 'a';

            int diff = abs(val1 - val2);
            sum += diff;
        }
        return sum;
    }
};
