 class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        bool hascenter = false;

        for (const string& word : words) {
            map[word]++;
        }

        int equal = 0; 
        int rev = 0;   

        for (auto it = map.begin(); it != map.end(); ++it) {
            string st = it->first;
            if (st[0] == st[1]) {
                
                if (it->second % 2 != 0) {
                    hascenter = true;
                    equal += it->second - 1;
                } else {
                    equal += it->second;
                }
            } else {
                string ts = st;
                reverse(ts.begin(), ts.end());
                if (map.find(ts) != map.end()) {
                    rev += min(it->second, map[ts]);
                }
            }
        }

        rev /= 2;

        return rev * 4 + equal * 2 + (hascenter ? 2 : 0);
    }
};