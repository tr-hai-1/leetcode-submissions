class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      vector<int> L(n), R(n), st;
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.back()] >= heights[i]) st.pop_back();
        if (st.empty()) L[i] = 0;
        else L[i] = st.back() + 1;
        st.push_back(i);
      } 
      st.clear();
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.back()] >= heights[i]) st.pop_back();
        if (st.empty()) R[i] = n - 1;
        else R[i] = st.back() - 1;
        st.push_back(i);
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        res = max(res, (R[i] - L[i] + 1) * heights[i]);
      }
      return res;
    }
};