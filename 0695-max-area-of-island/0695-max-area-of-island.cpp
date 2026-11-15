class Solution {
private:
  void dfs(int& curr, int x, int y, vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n) return;
    if (grid[x][y] != 1) return;
    curr++;
    grid[x][y] = 0;
    dfs(curr, x - 1, y, grid);
    dfs(curr, x + 1, y, grid);
    dfs(curr, x, y - 1, grid);
    dfs(curr, x, y + 1, grid);
  }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int curr, res = 0;
      int m = grid.size(), n = grid[0].size();
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j]) {
            curr = 0;
            dfs(curr, i, j, grid);
            res = max(res, curr);
          }
        }
      }
      return res;
    }
};