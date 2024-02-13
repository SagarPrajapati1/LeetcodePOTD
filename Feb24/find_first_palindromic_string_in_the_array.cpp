class Solution {
public:

    bool isPalindrome(string &str){
        int s = 0;
        int e = str.length() - 1;
        while(s <= e){
            if(str[s] != str[e]) return false;
            s++; e--;
        } 
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        
        for(int i = 0; i < words.size(); i++){
            string str = words[i];

            bool check = isPalindrome(str);
            if(check) return str;
        }
        return "";
    }
};
