class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
      int n = nums.size();
      int res = 1;
      int currInc = 1, currDec = 1;
      for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
          currInc++;
          currDec = 1;
        } else if (nums[i] < nums[i - 1]) {
          currDec++;
          currInc = 1;
        } else {
          currDec = 1;
          currInc = 1;
        }
        res = max({res, currInc, currDec});
      }    
      return res;
    }
};