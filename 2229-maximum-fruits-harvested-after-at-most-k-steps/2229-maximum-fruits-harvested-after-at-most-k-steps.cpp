class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        map<int, int> mp;
        for (auto x : fruits) {
            mp[x[0]] = x[1];
        }

        int ans = 0;
        int cur = 0;
        int l = max(0, startPos - k);

        for (int r = l; r <= startPos + k; r++) {
            if (mp.find(r) != mp.end()) {
                cur += mp[r];
            }

            while (l <= r && min(abs(startPos - l) + (r - l),
                                 abs(startPos - r) + (r - l)) > k) {
                if (mp.find(l) != mp.end()) {
                    cur -= mp[l];
                }
                l++;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};