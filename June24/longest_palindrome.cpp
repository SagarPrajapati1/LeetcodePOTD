class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mpp;
        int count=0;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(auto x:mpp){
            count+=(x.second/2);
        }
        if(2*count<s.size())return 2*count+1;
        return 2*count;
    }
};
