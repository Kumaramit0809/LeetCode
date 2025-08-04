class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits[0], m = 0, k = fruits.size(), ans = 0, totaln = 1, i,
            refn = 0, refm = 1, totalm = 0;
        if (k == 1) {
            return 1;
        }
        if (k == 2) {
            return 2;
        }
        for (i = 1; i < k; i++) {
            if (fruits[0] != fruits[i]) {
                totalm = 1;
                m = fruits[i];
                ans = max(ans, totalm + totaln);
                break;
            } else {

                totaln++;
            }
        }
        i++;
        for (; i < k; i++) {
            if (fruits[i] != n && fruits[i] != m) {

                if (fruits[i - 1] == n) {
                    totaln = refn;
                    m = fruits[i];
                    totalm = 0;
                }
                if (fruits[i - 1] == m) {
                    totalm = refm;
                    n = fruits[i];
                    totaln = 0;
                }
            }

            if (fruits[i] == n) {
                totaln++;
                refn++;
                refm = 0;
            }

            if (fruits[i] == m) {
                totalm++;
                refm++;
                refn = 0;
            }
            ans = max(ans, totalm + totaln);
        }
        ans = max(ans, totalm + totaln);
        return ans;
    }
};