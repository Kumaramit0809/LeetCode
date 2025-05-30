class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), sum = 0;
        vector<int> res(n, 1);

        if (n == 1)
            return 1;

        for (int i = 0; i < n - 1; i++) {
            if (ratings[i + 1] > ratings[i]) {
                res[i + 1] = res[i] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && res[i] <= res[i + 1]) {
                res[i] = res[i + 1] + 1;
            }

            sum += res[i];
        }

        sum += res[n - 1];

        return sum;
    }
};