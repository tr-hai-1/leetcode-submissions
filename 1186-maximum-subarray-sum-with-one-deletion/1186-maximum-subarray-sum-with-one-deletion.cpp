class Solution {
public:
    int maximumSum(vector<int>& arr) {
      int n = arr.size();
      vector<int> kadaneLeft(n, 0);
      vector<int> kadaneRight(n, 0);
      kadaneLeft[0] = arr[0], kadaneRight[n - 1] = arr[n - 1];
      int res = max(arr[0], arr[n - 1]);
      for (int i = 1; i < n; i++) {
        kadaneLeft[i] = max(kadaneLeft[i - 1] + arr[i], arr[i]);
        res = max(res, kadaneLeft[i]);
      }
      for (int i = n - 2; i >= 0; i--) {
        kadaneRight[i] = max(kadaneRight[i + 1] + arr[i], arr[i]);
      }
      for (int i = 0; i < n - 2; i++) {
        res = max(res, kadaneLeft[i] + kadaneRight[i + 2]);
      }
      return res;
    }
};