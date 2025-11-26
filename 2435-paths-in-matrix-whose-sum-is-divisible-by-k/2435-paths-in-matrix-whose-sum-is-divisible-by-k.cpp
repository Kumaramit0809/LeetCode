class Solution {
public:
    vector<vector<vector<int>>> dp;
    const int mod = 1e9 + 7;
    int m, n;
    int solve(vector<vector<int>>& grid, int& k, int i, int j, int rem) {
        if (i == m - 1 && j == n - 1) {
            return ((rem + grid[i][j]) % k == 0);
        }

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int right = 0, down = 0;

        if (i + 1 < m)
            down = solve(grid, k, i + 1, j, (rem + grid[i][j]) % k);
        if (j + 1 < n)
            right = solve(grid, k, i, j + 1, (rem + grid[i][j]) % k);

        return dp[i][j][rem] = (right + down) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));

        return solve(grid, k, 0, 0, 0);
    }
};