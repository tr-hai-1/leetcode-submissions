class Solution {
private:
  void addChar(string& str, char ch) {
    str += ch;
    return;
  }
  void deleteChar(string& str) {
    if (!str.empty()) str.pop_back();
    return;
  }
  void duplicateString(string& str) {
    string temp = str;
    for (char ch : temp) str += ch;
    return;
  }
  void reverseString(string& str) {
    reverse(str.begin(), str.end());
    return;
  }
public:
    string processStr(string s) {
      string res;
      for (char ch : s) {
        if (ch == '*') deleteChar(res);
        else if (ch == '#') duplicateString(res);
        else if (ch == '%') reverseString(res);
        else addChar(res, ch);
      }
      return res;
    }
};