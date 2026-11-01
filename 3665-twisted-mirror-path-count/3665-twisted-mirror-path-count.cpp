#define ll long long
const int MOD = 1e9 + 7;
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<vector<ll>>> dp(m, vector<vector<ll>> (n, vector<ll> (2, 0)));
      dp[0][0][0] = 1;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i > 0) {
            if (grid[i - 1][j]) dp[i][j][0] = dp[i - 1][j][1];
            else dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
          }
          if (j > 0) {
            if (grid[i][j - 1]) dp[i][j][1] = dp[i][j - 1][0];
            else dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
          }
        }
      }
      return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};