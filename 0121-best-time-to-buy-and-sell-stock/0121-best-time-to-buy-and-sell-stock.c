int maxProfit(int* prices, int pricesSize) {
  int mn = prices[0];
  int res = 0;
  for (int i = 1; i < pricesSize; i++) {
    if (prices[i] < mn) mn = prices[i];
    if (res <= prices[i] - mn) res = prices[i] - mn;
  }    
  return res;
}