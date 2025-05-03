class Solution {
    bool check(vector<vector<char>>& board, int row, int col, char digit) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit) {
                return false;
            }
            if (board[i][col] == digit) {
                return false;
            }
        }

        int sub_grid_start_row = (row / 3) * 3;
        int sub_grid_start_col = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[sub_grid_start_row + i][sub_grid_start_col + j] ==
                    digit) {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == '.') {
                    // Try digits 1 to 9.
                    for (char x = '1'; x <= '9'; x++) {
                        if (check(board, row, col, x)) {
                            board[row][col] = x;

                            // Recurse; if the board is solved, return true.
                            if (helper(board)) {
                                return true;
                            }

                            // Backtrack if placing x didn't lead to a solution.
                            board[row][col] = '.';
                        }
                    }
                    // Return false if no valid digit leads to a solution.
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
        return;
    }
};