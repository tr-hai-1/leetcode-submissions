class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
      int m = arr1.size();
      int n = arr2.size();
      bool stop;
      int res = 0;
      for (int i = 0; i < m; i++) {
        stop = 0;
        for (int j = 0; j < n; j++) {
          if (abs(arr1[i] - arr2[j]) <= d) {
            stop = 1;
            break;
          }
        }
        if (stop) continue;
        else res++;
      }
      return res;       
    }
};