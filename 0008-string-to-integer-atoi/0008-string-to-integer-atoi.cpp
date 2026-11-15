#define ll long long
class Solution {
public:
    int myAtoi(string s) {
      int n = s.size();
      if (n == 0) return 0;
      int pos = 0;
      ll res = 0;
      while (pos < n && s[pos] == ' ') {
        pos++;
      }
      if (pos >= n) return 0;
      int signPos = pos;
      if (s[pos] != '+' && s[pos] != '-' && (s[pos] - '0' < 0 || s[pos] - '0' > 9)) return 0;
      if (s[pos] == '+' || s[pos] == '-') pos++;
      if (pos >= n) return 0;
      if (s[pos] - '0' >= 0 && s[pos] - '0' <= 9) {
        res = 1LL * (s[pos] - '0');
        pos++;
      } else return 0;
      while (pos < n && s[pos] - '0' >= 0 && s[pos] - '0' <= 9) {
        int digit = s[pos++] - '0';
        res = res * 10 + digit;
        if (res > INT_MAX) return (s[signPos] == '-' ? INT_MIN : INT_MAX);
      }
      return s[signPos] == '-' ? -res : res;
    }
};