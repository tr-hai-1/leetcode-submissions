class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int> (n + 1, 0));
        for (auto vec : queries) {
            int x1 = vec[0], y1 = vec[1], x2 = vec[2], y2 = vec[3];
            diff[x1][y1]++;
            diff[x1][y2 + 1]--;
            diff[x2+ 1][y1]--;
            diff[x2 + 1][y2 + 1]++;
        }
        vector<vector<int>> res(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] += diff[i][j];
                if (i > 0) res[i][j] += res[i - 1][j];
                if (j > 0) res[i][j] += res[i][j - 1];
                if (i > 0 && j > 0) res[i][j] -= res[i - 1][j - 1];
            }
        }
        return res;
    }
};