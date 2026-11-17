class Solution {
private:
  bool dfs(int x, int y, int t, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    int n = grid.size();
    vis[x][y] = 1;
    if (x == n - 1 && y == n - 1) return 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] > t || vis[nx][ny]) continue;
      if (dfs(nx, ny, t, grid, vis)) return 1;
    }
    return 0;
  }
public:
    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();
      int l = 0, h = n * n - 1, res = 10000;
      while (l <= h) {
        vector<vector<bool>> vis(n, vector<bool> (n, 0));
        int m = l + (h - l) / 2;
        if (grid[0][0] <= m && dfs(0, 0, m, grid, vis)) {
          res = m;
          h = m - 1;
        } else l = m + 1;
      }
      return res;
    }
};