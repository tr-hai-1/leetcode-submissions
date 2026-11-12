class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int res = 0, curr = 0;
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        if (nums[i] == 0) curr = 0;
        else curr++;
        res = max(res, curr);
      }    
      return res;
    }
};