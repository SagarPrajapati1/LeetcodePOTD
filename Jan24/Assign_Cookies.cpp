class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        
        int n1 = g.size();
        int n2 = s.size();
        

        int cnt = 0;
        int i = n2-1; int j = n1-1;

        while(i  >= 0 and j >= 0 ) {
            if(s[i] >= g[j]) {
                cnt++;
                i--;
                j--;
            }   
            else j--;
        }
        return cnt;
    }
};
