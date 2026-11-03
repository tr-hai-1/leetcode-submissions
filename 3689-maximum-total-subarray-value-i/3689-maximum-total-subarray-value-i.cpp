class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
      int mx = *max_element(nums.begin(), nums.end());
      int mn = *min_element(nums.begin(), nums.end());
      long long res = 1LL * k * (mx - mn);
      return res;    
    }
};