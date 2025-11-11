class Solution {
public:
    pair<int, int> cnt(string str) {
        int cnt0 = 0;
        int cnt1 = 0;
        for (char c : str) {
            if (c == '0')
                cnt0++;
            if (c == '1')
                cnt1++;
        }
        return {cnt0, cnt1};
    }
    int rec(int i, int zero, int one, vector<string>& arr,
            vector<vector<vector<int>>>& dp) {
        if (i == 0) {
            if (cnt(arr[i]).first <= zero && cnt(arr[i]).second <= one)
                return 1;
            else
                return 0;
        }
        if (dp[i][zero][one] != -1)
            return dp[i][zero][one];
        int notpick = rec(i - 1, zero, one, arr, dp);
        int pick = -1e8;
        if (cnt(arr[i]).first <= zero && cnt(arr[i]).second <= one) {
            pick = 1 + rec(i - 1, zero - cnt(arr[i]).first,
                           one - cnt(arr[i]).second, arr, dp);
        }
        return dp[i][zero][one] = max(pick, notpick);
    }
    int findMaxForm(vector<string>& arr, int m, int n) {
        int len = arr.size();
        vector<vector<vector<int>>> dp(
            len, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return rec(len - 1, m, n, arr, dp);
    }
};