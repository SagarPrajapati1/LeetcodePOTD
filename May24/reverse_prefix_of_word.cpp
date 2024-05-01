class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        if (j != -1) {
            reverse(word.begin(), word.begin() + j + 1);
        }
        return word;
    }
};

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0; i < word.length(); i++){
            if(word[i] == ch){
                string str = word.substr(0, i+1);
                reverse(str.begin(), str.end());
                string ans = str + word.substr(i+1);
                return ans;
            }
        }
        return word;


    }
};
