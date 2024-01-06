class Solution {
public:
    vector<int> temp;
    int res = 0;

    int help(vector<vector<int > > &v, int i) {
        if(i == v.size()) return 0;

        if(temp[i] != -1) return temp[i];

        int next = find_next(v, v[i][1]);
        int select = help(v, next) + v[i][2];
        int not_select = help(v, i+1);

        temp[i] = max(select, not_select);
        res = max(res, temp[i]);

        return temp[i];

    }

    int find_next(vector<vector<int>>& jobs, int t) {
        int l = 0, r = jobs.size();
        while (l < r) {
            int m = l + (r-l)/2;
            if (jobs[m][0] >= t) {
                r = m;
            } else {
                l = m+1;
            }
        }
        
        return l;
    }


    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = st.size();
        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {st[i], et[i], profit[i]};
        }

        sort(v.begin(), v.end());

        temp = vector<int>(n, -1);
        help(v, 0);
        return res;
    }
};
