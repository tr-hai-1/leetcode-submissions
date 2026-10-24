class Solution {
public:
    int fib(int n) {
        int fi = 0, se = 1;
        if(n == 0) return fi;
        if(n == 1) return se;
        int temp;
        for(int i = 2; i <= n; i++) {
          temp = fi + se;
          fi = se;
          se = temp;
        }
        return se;
    }
};