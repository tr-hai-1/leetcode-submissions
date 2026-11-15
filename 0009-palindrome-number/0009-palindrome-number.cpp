#define ll long long
class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return 0;
      if (x < 10) return 1;
      int temp = x;
      ll res = 0LL;
      while (x > 0) {
        int digit = x % 10;
        res = res * 10 + digit;
        x /= 10;
      }
      return (res == temp);
    }
};