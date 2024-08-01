class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto it: details){
            string str = it.substr(11, 2);
            int age = stoi(str);
            if(age > 60) cnt++;
        }
        return cnt;
    }
};
