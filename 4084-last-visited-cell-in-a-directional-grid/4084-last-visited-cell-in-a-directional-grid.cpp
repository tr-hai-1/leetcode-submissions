class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, 0));
        vector<int> pos = {0, 0};
        vector<int> res = {0, 0};
        visited[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[pos[0]][pos[1]] == 'R') pos[1]++;
                else if (grid[pos[0]][pos[1]] == 'D') pos[0]++;
                else if (grid[pos[0]][pos[1]] == 'L') pos[1]--;
                else if (grid[pos[0]][pos[1]] == 'U') pos[0]--;
                if (pos[0] < 0 || pos[0] >= m || pos[1] < 0 || pos[1] >= n) return res;
                if (!visited[pos[0]][pos[1]]) {
                    visited[pos[0]][pos[1]] = 1;
                    res = {pos[0], pos[1]};
                }
            }
        }
        return res;
    }
};