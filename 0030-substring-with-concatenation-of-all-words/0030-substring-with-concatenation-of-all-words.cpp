class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> word;
        int n = s.size();
        int wordsLen = words.size();
        vector<int> ans;

        for (int i = 0; i < wordsLen; i++) {
            word[words[i]]++;
        }

        int wordLen = words[0].size();

        for (int start = 0; start < wordLen; start++) {
            unordered_map<string, int> visited;
            int count = 0;

            for (int index = start; index + wordLen <= n;
                 index = index + wordLen) {
                string str = s.substr(index, wordLen);
                if (word.find(str) == word.end()) {
                    visited.clear();
                    count = 0;
                } else {
                    visited[str]++;
                    count++;

                    while (word[str] < visited[str]) {
                        count--;
                        string temp =
                            s.substr(index - (count * wordLen), wordLen);
                        visited[temp]--;
                    }

                    if (count == wordsLen) {
                        ans.push_back(index - ((count - 1) * wordLen));
                    }
                }
            }
        }
        return ans;
    }
};