#define ll long long
class Solution {
public:
    long long minimumCost(ll cost1, ll cost2, ll costBoth, ll need1, ll need2) {
      if (costBoth < cost1 && costBoth < cost2) 
        return 1LL * max(need1, need2) * costBoth;
      if (costBoth >= cost1 + cost2)
        return 1LL * (cost1 * need1 + cost2 * need2);
      if (need1 > need2) 
        return 1LL * (costBoth * need2 + (need1 - need2) * min(costBoth, cost1));
      return 1LL * (costBoth * need1 + (need2 - need1) * min(costBoth, cost2));
    }
};