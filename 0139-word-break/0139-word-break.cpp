class Solution {
public:
    bool starts(string s, string t) {
        if (s.length() < t.length())
            return false;
        int i = 0;
        for (char& c : t) {
            if (c != s[i++]) {
                return false;
            }
        }
        return true;
    }

    unordered_map<string, int> u;

    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0) {
            // cout << "Yes";
            u[s] = 1;
            return true;
        }
        for (string& t : wordDict) {
            if (starts(s, t)) {
                string rest = s.substr(t.length());
                if (u[rest] != 0) {
                    return u[rest] > 0;
                }
                if (wordBreak(rest, wordDict)) {
                    u[s] = 1;
                    return true;
                }
            }
        }
        u[s] = -1;
        return false;
    }
};