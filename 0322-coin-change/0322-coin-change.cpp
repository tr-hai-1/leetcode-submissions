class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<long long> dp(amount + 1, LONG_LONG_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != LONG_LONG_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        return (dp[amount] == LONG_LONG_MAX ? -1 : dp[amount]);
    }
};