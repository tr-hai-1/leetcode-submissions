class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size(), n = nums2.size();
      vector<int> st;
      vector<int> helper(n, 0);
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.back() <= nums2[i]) st.pop_back();
        if (st.empty()) helper[i] = -1;
        else helper[i] = st.back();
        st.push_back(nums2[i]);
      }    
      int mx = *max_element(nums2.begin(), nums2.end());
      vector<int> mp(mx + 1, 0);
      for (int i = 0; i < n; i++) {
        mp[nums2[i]] = i;
      }
      vector<int> res(m);
      for (int i = 0; i < m; i++) {
        res[i] = helper[mp[nums1[i]]];
      }
      return res;
    }
};