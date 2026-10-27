class Solution {
public:
    vector<string> createGrid(int m, int n) {
      vector<string> res(m, string(n, '.'));
      for (int i = 1; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
          res[i][j] = '#';
        }
      }
      return res;
    }
};