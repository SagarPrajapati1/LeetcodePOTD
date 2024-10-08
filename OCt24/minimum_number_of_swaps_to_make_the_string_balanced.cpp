class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;
    }
};



class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int balance = 0, swaps = 0, j=n-1;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '[') balance++;
            else balance--;

            if(balance < 0)
            {
                while(i<j && s[j] != '[') j--;
                swap(s[i], s[j]);
                swaps++;
                balance = 1;
            }
        }
        return swaps;
    }
};
