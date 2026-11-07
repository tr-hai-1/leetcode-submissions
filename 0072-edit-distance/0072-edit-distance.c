int dp[501][501] = {0};
int minDistance(char* word1, char* word2) {
  int m = strlen(word1);
  int n = strlen(word2);
  for (int i = 1; i <= m; i++) dp[i][0] = i;
  for (int j = 1; j <= n; j++) dp[0][j] = j;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else {
        int mn = dp[i - 1][j - 1];
        if (dp[i][j - 1] < mn) mn = dp[i][j - 1];
        if (dp[i - 1][j] < mn) mn = dp[i - 1][j];
        dp[i][j] = mn + 1;
      }
    }
  }
  return dp[m][n];
}