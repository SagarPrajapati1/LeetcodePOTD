class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();

        if(s == t) return 0;

        int arr[26] = {0};

        for(int i = 0; i < n;  i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        int ans = 0;
        for(int i : arr){
            if(i > 0) ans+=i;
        }
        return ans;
        
    }
};
