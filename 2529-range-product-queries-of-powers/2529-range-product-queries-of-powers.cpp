class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) { return modPow(x, MOD - 2); }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        long long bit = 1;
        int temp = n;

        while (temp > 0) {
            if (temp & 1) {
                powers.push_back(bit);
            }
            temp >>= 1;
            bit <<= 1;
        }

        int m = powers.size();
        vector<long long> prefix(m);
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i - 1] * powers[i]) % MOD;
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                ans.push_back((int)prefix[r]);
            } else {
                long long result =
                    (prefix[r] * modInverse(prefix[l - 1])) % MOD;
                ans.push_back((int)result);
            }
        }
        return ans;
    }
};
