bool dfs(char** board, int boardSize, int* boardColSize, char* word, int r, int c, int k) {
  if (r < 0 || r >= boardSize || c < 0 || c >= boardColSize[r]) return 0;
  if (board[r][c] != word[k]) return 0;
  if (word[k + 1] == '\0') return 1;
  char saved = board[r][c];
  board[r][c] = '.';
  bool found = (dfs(board, boardSize, boardColSize, word, r - 1, c, k + 1) || dfs(board, boardSize, boardColSize, word, r + 1, c, k + 1) || dfs(board, boardSize, boardColSize, word, r, c - 1, k + 1) || dfs(board, boardSize, boardColSize, word, r, c + 1, k + 1));
  board[r][c] = saved;
  return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
  for (int r = 0; r < boardSize; r++) {
    for (int c = 0; c < boardColSize[r]; c++) {
      if (dfs(board, boardSize, boardColSize, word, r, c, 0)) return 1;
    }
  }
  return 0;
}