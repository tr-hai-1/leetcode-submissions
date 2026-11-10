class Solution {
private:
  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= (int)grid.size() || j >= (int)grid[0].size() || grid[i][j] != '1') return;
    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
public:
    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty() || grid[0].empty()) return 0;
      int res = 0;
      for (int i = 0; i < (int)grid.size(); i++) {
        for (int j = 0; j < (int)grid[0].size(); j++) {
          if (grid[i][j] == '1') {
            res++;
            dfs(grid, i, j);
          }
        }
      }
      return res;
    }
};