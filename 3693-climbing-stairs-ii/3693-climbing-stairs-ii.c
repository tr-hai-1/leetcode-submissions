int climbStairs(int n, int* costs, int costsSize) {
  int f0 = 0, f1 = 0, f2 = 0;
  for (int i = 0; i < n; i++) {
    int c = costs[i];
    int mn = f0 + 9;
    if (f1 + 4 < mn) mn = f1 + 4;
    if (f2 + 1 < mn) mn = f2 + 1;
    int next = mn + c;
    f0 = f1;
    f1 = f2;
    f2 = next;
  }
  return f2;
}