void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
  if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i] || grid[i][j] != '1') return;
  grid[i][j] = '0';
  dfs(grid, gridSize, gridColSize, i + 1, j);
  dfs(grid, gridSize, gridColSize, i - 1, j);
  dfs(grid, gridSize, gridColSize, i, j + 1);
  dfs(grid, gridSize, gridColSize, i, j - 1);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
  int res = 0;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridColSize[i]; j++) {
      if (grid[i][j] == '1') {
        res++;
        dfs(grid, gridSize, gridColSize, i, j);
      }
    }
  }
  return res;
}