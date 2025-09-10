class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = languages.size();
        unordered_map<int, unordered_set<int>> mp;

        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                mp[i + 1].insert(lang);
            }
        }

        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (int lang : mp[u]) {
                if (mp[v].count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

        vector<int> freq(n + 1, 0);
        int maxFreq = 0;
        for (int person : needTeach) {
            for (int lang : mp[person]) {
                freq[lang]++;
                maxFreq = max(maxFreq, freq[lang]);
            }
        }

        return (int)needTeach.size() - maxFreq;
    }
};