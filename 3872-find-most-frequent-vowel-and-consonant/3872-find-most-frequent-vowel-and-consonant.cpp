class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        string vowels = "aeiou";

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxVowel = 0, maxConsonant = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                char ch = 'a' + i;
                if (vowels.find(ch) != string::npos) {
                    maxVowel = max(maxVowel, freq[i]);
                } else {
                    maxConsonant = max(maxConsonant, freq[i]);
                }
            }
        }

        return maxVowel + maxConsonant;
    }
};