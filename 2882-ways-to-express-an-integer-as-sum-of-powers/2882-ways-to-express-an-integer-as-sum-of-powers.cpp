class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int n, int x, int j, vector<vector<int>>& dp) {
        if (int(pow(j, x)) > n) {
            return 0;
        }

        if (dp[n][j] != -1) {
            return dp[n][j];
        }

        int take, notTake = 0;
        if (int(pow(j, x)) < n) {
            take = helper(n - int(pow(j, x)), x, j + 1, dp);
        }

        if (int(pow(j, x) == n)) {
            return 1;
        }

        notTake = helper(n, x, j + 1, dp);

        return dp[n][j] = (take + notTake) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(n, x, 1, dp);
    }
};