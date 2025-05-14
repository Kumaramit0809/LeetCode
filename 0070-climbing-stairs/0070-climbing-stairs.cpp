class Solution {
public:
    int countWays(vector<int>& dp, int n) {
        
        if(dp[n] != -1) return dp[n];

        dp[n] = countWays(dp, n - 1) + countWays(dp, n - 2);
        return dp[n];
    }

    int climbStairs(int n) {
        
        if(n == 1 || n == 2) return n;

        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        dp[2] = 2;

        return countWays(dp, n);
        
    }
};