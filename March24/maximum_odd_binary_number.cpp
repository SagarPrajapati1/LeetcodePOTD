class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        // brute force
        // int cnt = 0;
        // int cnt0 = 0;
        // for(int i = 0; i < s.length(); i++)
        // {
        //     if(s[i] == '1') cnt++;
        //     else cnt0++;
        // }
        // if(cnt == s.length()) return s;

        // if(cnt == 1){
        //     int i = 0;
        //     string str = "";
        //     while(i < s.length() - 1) {
        //         str += '0';
        //         i++;
        //     }
        //     str += '1';
        //     return str;
        // }
        // string str = "";
        // while(cnt > 1){
        //     str += '1';
        //     cnt--;
        // }
        // while (cnt0--){
        //     str += '0';
        // }
        // str += '1';
        // return str;

        // better one clean code

        int oneCnt = 0;
        int zeroCnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') oneCnt++;
            else zeroCnt++;
        }

        string str = string(oneCnt - 1, '1') + string(zeroCnt, '0') + '1';
        return str;
    }
};
