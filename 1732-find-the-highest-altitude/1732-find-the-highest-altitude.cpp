class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int altitude = 0;
      int res = -10001;
      for (int x : gain) {
        altitude += x;
        res = max(res, altitude);
      }     
      return max(res, 0);
    }
};