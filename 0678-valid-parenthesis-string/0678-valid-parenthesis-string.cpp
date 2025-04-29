class Solution {
public:
    bool checkValidString(string s) {
        int leftBalance = 0;
        int rightBalance = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') {
                leftBalance++;
            } else {
                leftBalance--;
            }
            if (leftBalance < 0)
                return false;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                rightBalance++;
            } else {
                rightBalance--;
            }
            if (rightBalance < 0)
                return false;
        }

        return true;
    }
};