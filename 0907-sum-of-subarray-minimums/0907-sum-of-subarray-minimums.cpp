using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      vector<int> L(n), R(n), st;
      for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.back()] > arr[i]) st.pop_back();
        if (st.empty()) L[i] = 0;
        else L[i] = st.back() + 1;
        st.push_back(i);
      }
      st.clear();
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
        if (st.empty()) R[i] = n - 1;
        else R[i] = st.back() - 1;
        st.push_back(i);
      }
      ll res = 0;
      for (int i = 0; i < n; i++) {
        ll d = 1LL * (i - L[i] + 1) * (R[i] - i + 1) % MOD;
        res = (res + d * arr[i]) % MOD;
      }
      return res;
    }
};