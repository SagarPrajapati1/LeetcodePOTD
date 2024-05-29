class Solution {
public:
    void half(deque<char>& s)
    {
        s.pop_back();
    }

    void add_one(deque<char> & s)
    {
        int i = s.size()-1;
        for(; i >= 0 ; i-- )
        {
            if(s[i] == '0') break;
            else s[i] = '0';
        }

        if(i >= 0)
        s[i]='1';
        else
        s.push_front('1');
    }

    bool is_one(deque<char> s)
    {
        return s.size() == 1;
    }

    bool is_odd(deque<char> s)
    {
        return s.back() == '1';
    }


    int numSteps(string s) 
    {
        deque<char> d(s.begin() , s.end());
        int ans = 0;
        while(true)
        {
            if(is_one(d)) break;

            ans++;

            if(is_odd(d)) add_one(d);
            else half(d);
        }
        return ans;
        
    }
};
