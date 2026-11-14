class Solution {
private:
  int m, n;
  bool dfs(vector<vector<char>>& board, string& word, int r, int c, int k) {
    if (r < 0 || r >= m || c < 0 || c >= n) return 0;
    if (board[r][c] != word[k]) return 0;
    if (k == (int)word.size() - 1) return 1;
    char saved = board[r][c];
    board[r][c] = '#';
    bool found = (dfs(board, word, r - 1, c, k + 1) || dfs(board, word, r + 1, c, k + 1) || dfs(board, word, r, c - 1, k + 1) || dfs(board, word, r, c + 1, k + 1));
    board[r][c] = saved;
    return found;
  }
public:
    bool exist(vector<vector<char>>& board, string word) {
      m = board.size(), n = board[0].size();
      if ((int)word.size() > m * n) return 0;
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (dfs(board, word, r, c, 0)) return 1;
        }
      }
      return 0;
    }
};