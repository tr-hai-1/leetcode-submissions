int min(int a, int b) {
  if (a <= b) return a;
  else return b;
}

int climbStairs(int n, int* costs, int costsSize) {
  int dp[100100] = {};
  for (int i = 1; i <= n; i++) dp[i] = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= 3; k++) {
      if (i >= k) dp[i] = min(dp[i], dp[i - k] + costs[i - 1] + k * k);
    }
  }
  return dp[n];
}