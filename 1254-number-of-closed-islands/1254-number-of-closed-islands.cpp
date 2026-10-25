class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      int res = 0;
      int dx[] = {-1, 1, 0, 0};
      int dy[] = {0, 0, -1, 1};
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          if(!grid[i][j]) {
            grid[i][j] = 1;
            bool closed = 1;
            res++;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()) {
              int x = q.front().first;
              int y = q.front().second;
              q.pop();
              for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                  if(closed) {
                    closed = 0;
                    res--;
                  }
                  continue;
                }
                if(grid[nx][ny]) continue;
                q.push({nx, ny});
                grid[nx][ny] = 1;
              }
            }
          }
        }
      }
      return res;
    }
};