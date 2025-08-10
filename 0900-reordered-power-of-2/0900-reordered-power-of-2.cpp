class Solution {
public:
    string getCount(int n) {
        string count(10, '0');
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
        }
        return count;
    }
    bool reorderedPowerOf2(int n) {
        static unordered_set<string> powerOfTwoCounts;
        if (powerOfTwoCounts.empty()) {
            for (int i = 1; i <= 1e9; i <<= 1) {
                powerOfTwoCounts.insert(getCount(i));
            }
        }
        return powerOfTwoCounts.count(getCount(n));
    }
};