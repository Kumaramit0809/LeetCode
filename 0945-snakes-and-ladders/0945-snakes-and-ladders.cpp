class Solution {
public:
    pair<int, int> getCoord(int num, int n) {
        int q = (num - 1) / n;
        int rem = (num - 1) % n;
        int row = n - 1 - q;
        int col;
        if (q % 2 == 0) {
            col = rem;
        } else {
            col = n - 1 - rem;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        vector<int> vis(n * n + 1, 0);
        int steps = 1;
        vis[1] = 1;
        q.push(1);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int curr = q.front();
                q.pop();
                for (int i = 1; i <= 6; i++) {
                    int next = curr + i;
                    if (next > n * n)
                        continue;
                    auto [row, col] = getCoord(next, n);
                    if (board[row][col] != -1) {
                        next = board[row][col];
                    }
                    if (!vis[next]) {
                        if (next == n * n)
                            return steps;
                        q.push(next);
                        vis[next] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};