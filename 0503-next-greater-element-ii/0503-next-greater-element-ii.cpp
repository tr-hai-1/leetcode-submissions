class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();
      vector<int> a(2 * n);
      for (int i = 0; i < n; i++) a[i] = nums[i];
      for (int i = n; i < 2 * n; i++) a[i] = nums[i - n];
      vector<int> st;
      vector<int> helper(2 * n);
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.back() <= a[i]) st.pop_back();
        if (st.empty()) helper[i] = -1;
        else helper[i] = st.back();
        st.push_back(a[i]);
      }   
      vector<int> res(n);
      for (int i = 0; i < n; i++) res[i] = helper[i];
      return res;
    }
};