class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            int k = i + j;
            if (i < s1.size() && s1[i] == s3[k] && !visited.count({i + 1, j})) {
                q.push({i + 1, j});
                visited.insert({i + 1, j});
            }
            if (j < s2.size() && s2[j] == s3[k] && !visited.count({i, j + 1})) {
                q.push({i, j + 1});
                visited.insert({i, j + 1});
            }

            if (i + j == s3.size() && i == s1.size() && j == s2.size()) {
                return true;
            }
        }

        return false;
    }
};
