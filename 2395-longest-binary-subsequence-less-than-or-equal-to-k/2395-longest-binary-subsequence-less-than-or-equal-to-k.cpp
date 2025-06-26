class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[n - 1 - i] == '0') {
                count++;
            } else {
                if (i < 31 && 1 << i <= k) {
                    count++;
                    k -= 1 << i;
                }
            }
        }

        return count;
    }
};