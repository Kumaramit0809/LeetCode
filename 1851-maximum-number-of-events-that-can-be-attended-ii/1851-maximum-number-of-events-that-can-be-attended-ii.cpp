class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int findNextEvent(const vector<vector<int>>& events, int i) {
        int low = i + 1, high = events.size() - 1, ans = events.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > events[i][1]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int solve(int i, int k, const vector<vector<int>>& events) {
        if (i == n || k == 0) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        int skip = solve(i + 1, k, events);

        int nextIndex = findNextEvent(events, i);
        int take = events[i][2] + solve(nextIndex, k - 1, events);

        return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());  
        n = events.size();
        dp.assign(n, vector<int>(k + 1, -1));
        return solve(0, k, events);
    }
};
