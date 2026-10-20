class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        int start = image[sr][sc];
        if (start == color)
            return image;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || image[nx][ny] != start)
                    continue;
                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }
        return image;
    }
};