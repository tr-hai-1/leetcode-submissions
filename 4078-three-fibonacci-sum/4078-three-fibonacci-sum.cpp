class Solution {
public:
    bool threeFibonacciSum(int n) {
      const int lim = 46;
      vector<int> fib(lim + 1);
      for(int i = 0; i <= lim; i++) {
        if(i < 2) {
          fib[i] = i;
          continue;
        }
        fib[i] = fib[i - 1] + fib[i - 2];
      }
      long long sum;
      for(int i = 0; i <= lim - 2; i++) {
        sum = 1LL * fib[i] + fib[i + 1] + fib[i + 2];
        if(sum == n) return true;
      } 
      return false;
    }
};