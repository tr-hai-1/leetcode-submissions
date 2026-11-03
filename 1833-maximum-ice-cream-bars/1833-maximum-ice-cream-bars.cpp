class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      int res = 0;
      sort(costs.begin(), costs.end());
      for (int i = 0; i < (int)costs.size(); i++) {
        if (costs[i] <= coins) coins -= costs[i];
        else break;
        res++;
      }
      return res;
    }
};