class Solution {
public:
    bool isBaseKPalindrome(int k, long long num) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % k);
            num /= k;
        }
        int l = 0, r = digits.size() - 1;
        while (l < r) {
            if (digits[l++] != digits[r--]) return false;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int len = 1;
        
        while (n > 0) {
            int halfLen = (len + 1) / 2;
            long long minNum = (len == 1) ? 1 : pow(10, halfLen - 1);
            long long maxNum = pow(10, halfLen) - 1;

            for (long long i = minNum; i <= maxNum; ++i) {
                string s = to_string(i);
                string rs = s;
                reverse(rs.begin(), rs.end());

                string palStr = (len % 2 == 0) ? s + rs : s + rs.substr(1);
                long long pal = stoll(palStr);

                if (isBaseKPalindrome(k, pal)) {
                    sum += pal;
                    if (--n == 0) return sum;
                }
            }
            len++;
        }

        return sum;
    }
};
