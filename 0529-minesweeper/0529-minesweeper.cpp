class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();
        int clickR = click[0];
        int clickC = click[1];
        if (board[clickR][clickC] == 'M') {
            board[clickR][clickC] = 'X';
            return board;
        }
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({clickR, clickC});
        board[clickR][clickC] = 'B';
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int mines = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
                    continue;
                if (board[nx][ny] == 'M')
                    mines++;
            }
            if (mines > 0) {
                board[x][y] = mines + '0';
                continue;
            }
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
                    continue;
                if (board[nx][ny] == 'E') {
                    board[nx][ny] = 'B';
                    q.push({nx, ny});
                }
            }
        }
        return board;
    }
};