class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

        // fill distance matrix
        for(auto it: edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // floyd Warshal algo
        // diagonal distance is 0
        for(int i = 0; i < n; ++i) dist[i][i] = 0;

        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // find city
        int cntCity = n;
        int cityNo = -1; // coz city no can be start from 0 that's why initialize with -1

        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity < n; adjCity++) {
                if(dist[city][adjCity] <= dT){
                    cnt++;
                }
            }

            if(cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};
