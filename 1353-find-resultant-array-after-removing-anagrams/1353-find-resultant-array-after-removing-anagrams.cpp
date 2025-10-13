class Solution {
public:
    bool isAna(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return (s1 == s2);
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (!ans.empty() && isAna(ans.back(), words[i]))
                continue;
            ans.push_back(words[i]);
        }
        return ans;
    }
};