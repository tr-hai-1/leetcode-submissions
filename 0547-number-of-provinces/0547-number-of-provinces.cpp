class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      set<int> seen;
      int res = 0;
      for (int city = 0; city < (int)isConnected.size(); city++) {
        if (seen.find(city) == seen.end()) {
          res++;
          dfs(city, isConnected, seen);
        }
      }
      return res;
    }
private:
  void dfs(int city, vector<vector<int>>& isConnected, set<int>& seen) {
    seen.insert(city);
    for (int curr = 0; curr < (int)isConnected[city].size(); curr++) {
      int connected = isConnected[city][curr];
      if (connected && seen.find(curr) == seen.end()) dfs(curr, isConnected, seen);
    }
    return;
  }
};