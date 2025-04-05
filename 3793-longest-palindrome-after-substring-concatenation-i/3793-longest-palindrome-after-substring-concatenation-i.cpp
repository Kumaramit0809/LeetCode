class Solution {
public:
    bool isPalindrome(const string& str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int maxLen = 0;

        // Iterate over all substrings of s
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = i; j <= s.size(); ++j) {
                string s_sub = s.substr(i, j - i);  // substring from s

                // Iterate over all substrings of t
                for (int x = 0; x <= t.size(); ++x) {
                    for (int y = x; y <= t.size(); ++y) {
                        string t_sub = t.substr(x, y - x);  // substring from t
                        string combined = s_sub + t_sub;

                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.length());
                        }
                    }
                }
            }
        }

        return maxLen;
    }
};