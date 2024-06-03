class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_index=0;
        int s_index=0;
        while(s_index<s.size() && t_index<t.size()){
            while(s_index<s.size() && t[t_index]!=s[s_index]){ //loop to match characters
                s_index++;
            }
            if(s_index<s.size()){ //if matched then increment index of both strings
                s_index++;
                t_index++;
            }

        }        
        if(t.size()-t_index>0) return t.size()-t_index;
        return 0;    
    }
};
