class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      vector<int> cnt(n + 1, 0);
      for (int i = 0; i < n; i++) {
        cnt[nums[i]]++;
      }
      int fi, se;
      for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2) fi = i;
        else if (cnt[i] == 0) se = i;
      }
      return {fi, se};
    }
};