class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int> st;
      vector<int> res(n, 0);
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temperatures[st.back()] <= temperatures[i]) st.pop_back();
        if (st.empty()) res[i] = i;
        else res[i] = st.back();
        st.push_back(i);
      }   
      for (int i = 0; i < n; i++) {
        res[i] -= i;
      }
      return res;
    }
};