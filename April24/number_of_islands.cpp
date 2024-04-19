// class Solution {
//   private: 
//   void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
//       // mark it visited
//       vis[row][col] = 1; 
//       queue<pair<int,int>> q;
//       // push the node in queue
//       q.push({row, col}); 
//       int n = grid.size(); 
//       int m = grid[0].size(); 
      
//       // until the queue becomes empty
//       while(!q.empty()) {
//           int row = q.front().first; 
//           int col = q.front().second; 
//           q.pop(); 
          
//           // traverse in the neighbours and mark them if its a land 
//           for(int delrow = -1; delrow<=1;delrow++) {
//               for(int delcol = -1; delcol <= 1; delcol++) {
//                   int nrow = row + delrow; 
//                   int ncol = col + delcol; 
//                   // neighbour row and column is valid, and is an unvisited land
//                   if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
//                   && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
//                       vis[nrow][ncol] = 1; 
//                       q.push({nrow, ncol}); 
//                   }
//               }
//           }
//       }
//   }
//   public:
//     // Function to find the number of islands.
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size(); 
//         int m = grid[0].size(); 
//         // create visited array and initialise to 0
//         vector<vector<int>> vis(n, vector<int>(m, 0)); 
//         int cnt = 0; 
//         for(int row = 0; row < n ; row++) {
//             for(int col = 0; col < m ;col++) {
//                 // if not visited and is a land
//                 if(!vis[row][col] && grid[row][col] == '1') {
//                     cnt++; 
//                     bfs(row, col, vis, grid); 
//                 }
//             }
//         }
//         return cnt; 
//     }
// };

class Solution {
public:
    void solve(int i, int j, vector<vector<char>> &grid){
        if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] == '*' || grid[i][j] == '0')
            return;

        grid[i][j] = '*';
        solve(i + 1, j, grid);
        solve(i - 1, j, grid);
        solve(i, j + 1, grid);
        solve(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    counter++;
                    solve(i, j, grid);
                }

        return counter;
    }
};
