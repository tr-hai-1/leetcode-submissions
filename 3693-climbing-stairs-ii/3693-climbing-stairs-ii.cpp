#define ll long long
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
      int dp0 = 0, dp1 = 0, dp2 = 0;
      for (int c : costs) {
        int next = min({dp0 + 9, dp1 + 4, dp2 + 1}) + c;
        dp0 = dp1;
        dp1 = dp2;
        dp2 = next;
      }
      return dp2;
    }
};