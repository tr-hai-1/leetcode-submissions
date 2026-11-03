class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      int initialCoins = coins;
      vector<int> cnt(initialCoins + 1);
      for (int cost : costs) {
        if (cost > initialCoins) continue;
        else cnt[cost]++;
      }
      int res = 0;
      for (int cost = 0; cost <= initialCoins; cost++) {
        while (cnt[cost] > 0) {
          if (cost > coins) return res;
          res++;
          coins -= cost;
          cnt[cost]--;
        }
      }
      return res;
    }
};