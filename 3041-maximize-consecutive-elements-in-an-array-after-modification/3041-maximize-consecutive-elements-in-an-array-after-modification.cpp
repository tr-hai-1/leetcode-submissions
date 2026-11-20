class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int res = 0;
      unordered_map<int, int> dp;
      for (int num : nums) {
        dp[num + 1] = dp[num] + 1;
        dp[num] = dp[num - 1] + 1;
        res = max({res, dp[num], dp[num + 1]});
      }
      return res;
    }
};