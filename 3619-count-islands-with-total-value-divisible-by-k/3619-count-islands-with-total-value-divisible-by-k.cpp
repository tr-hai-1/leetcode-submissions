#define ll long long
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();
      int res = 0;
      int dx[] = {-1, 1, 0, 0};
      int dy[] = {0, 0, -1, 1};
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j]) {
            ll sum = grid[i][j];
            queue<pair<int, int>> q;
            q.push({i, j});
            grid[i][j] = 0;
            while (!q.empty()) {
              int x = q.front().first;
              int y = q.front().second;
              q.pop();
              for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny]) continue;
                sum += 1LL * grid[nx][ny];
                q.push({nx, ny});
                grid[nx][ny] = 0;
              }
            }
            if (q.empty()) {
              if (sum % k == 0) res++;
            }
          } 
        }
      }
      return res;
    }
};