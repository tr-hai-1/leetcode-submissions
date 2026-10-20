class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int> (n + 1, 0));
        for (const auto& q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            diff[x1][y1]++;
            diff[x2 + 1][y1]--;
            diff[x1][y2 + 1]--;
            diff[x2 + 1][y2 + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                diff[i][j] += diff[i - 1][j];
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }
        vector<vector<int>> res(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] += diff[i][j];
            }
        }
        return res;
    }
};