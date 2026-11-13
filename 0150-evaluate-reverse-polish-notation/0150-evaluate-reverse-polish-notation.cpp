class Solution {
private:
  int stringToInt(string& str) {
    int res = 0;
    int factor = 1;
    int n = str.size();
    for (int i = n - 1; i >= 0; i--) {
      if (str[i] == '-') {
        res = -res;
        break;
      }
      int digit = str[i] - '0';
      res += digit * factor;
      factor *= 10;
    }
    return res;
  }

public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;
      for (string& s : tokens) {
        if (s != "+" && s != "-" && s != "*" && s != "/") {
          int x = stringToInt(s);
          st.push(x);
          continue;
        }
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        int res;
        if (s == "+") res = a + b;
        else if (s == "-") res = b - a;
        else if (s == "*") res = a * b;
        else res = b / a;
        st.push(res);
      }   
      return st.top();
    }
};