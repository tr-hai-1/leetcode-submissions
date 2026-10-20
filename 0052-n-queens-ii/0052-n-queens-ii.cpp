class Solution {
public:
    bool isValid (int row, int col, int n, vector<string>& board) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') 
                return false;
        }

        return true;
    }

    void backtracking(int row, int n, vector<string>& board, int& ans) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n, board)) {
                board[row][col] = 'Q';
                backtracking(row + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int ans = 0;
        backtracking(0, n, board, ans);
        return ans;    
    }
};