class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      int n = nums.size();
      vector<int> helper(101, 0);
      for (int i = 0; i < n; i++) {
        helper[nums[i]]++;
      }
      for (int i = 1; i <= 100; i++) {
        helper[i] += helper[i - 1];
      }
      vector<int> res(n);
      for (int i = 0; i < n; i++) {
        if (nums[i] == 0) res[i] = 0;
        else res[i] = helper[nums[i] - 1];
      }
      return res;
    }
};