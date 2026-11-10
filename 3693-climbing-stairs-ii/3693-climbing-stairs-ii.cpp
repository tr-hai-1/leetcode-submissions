#define ll long long
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
      vector<ll> dp(n + 1, LONG_LONG_MAX);
      dp[0] = 0;
      for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 3; k++) {
          if (i >= k) dp[i] = min(dp[i], 1LL * (dp[i - k] + costs[i - 1] + k * k));
        }
      }
      return dp[n];
    }
};