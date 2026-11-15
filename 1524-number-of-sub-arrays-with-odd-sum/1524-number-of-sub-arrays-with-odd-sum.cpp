const int MOD = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
      int currOdd = 0, currEven = 0, prevOdd = 0, prevEven = 0, res = 0;
      for (int x : arr) {
        prevOdd = currOdd, prevEven = currEven;
        if (x % 2 == 1) {
          currOdd = (1 + prevEven) % MOD;
          currEven = prevOdd;
        } else {
          currEven = (1 + prevEven) % MOD;
          currOdd = prevOdd;
        }
        res = (res + currOdd) % MOD;
      }
      return res;
    }
};