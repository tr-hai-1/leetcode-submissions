class Solution {
private:
  void dfs(int& curr, int k, vector<int>& nums, set<int>& seen) {
    if (seen.find(k) != seen.end()) return;
    seen.insert(k);
    curr++;
    dfs(curr, nums[k], nums, seen);
  }
public:
    int arrayNesting(vector<int>& nums) {
      set<int> seen;
      int curr, res = 0;
      for (int i = 0; i < (int)nums.size(); i++) {
        if (seen.find(i) == seen.end()) {
          curr = 0;
          dfs(curr, i, nums, seen);
          res = max(res, curr);
        }
      }
      return res;
    }
};