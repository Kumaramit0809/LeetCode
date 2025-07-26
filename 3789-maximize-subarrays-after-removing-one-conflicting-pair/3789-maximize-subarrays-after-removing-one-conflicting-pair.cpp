#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        const long long INFY = (long long)n + 5;

        int m = (int)conflictingPairs.size();
        struct Pair { int x, y, id; };
        vector<vector<Pair>> at(n + 2); 
        for (int i = 0; i < m; ++i) {
            int a = conflictingPairs[i][0];
            int b = conflictingPairs[i][1];
            if (a > b) swap(a, b);
            at[a].push_back({a, b, i});
        }
        using Node = pair<int,int>;
        multiset<Node> ms;

        long long total = 1LL * n * (n + 1) / 2;
        long long invalid_total = 0;

        vector<long long> delta(m, 0);

        for (int l = n; l >= 1; --l) {
            for (auto &p : at[l]) {
                ms.insert({p.y, p.id});
            }

            if (ms.empty()) continue;
            auto it1 = ms.begin();
            int y1 = it1->first;
            int id1 = it1->second;
            long long y2 = INFY;
            if (ms.size() >= 2) {
                auto it2 = next(it1);
                y2 = it2->first;
            }
            long long inv_here = (y1 <= n) ? (n - y1 + 1) : 0;
            invalid_total += inv_here;
            if (y1 <= n) {
                long long inv_after_remove = (y2 <= n) ? (n - (int)y2 + 1) : 0;
                delta[id1] += (inv_here - inv_after_remove);
            }
        }

        long long base_valid = total - invalid_total;
        long long best_gain = 0;
        for (int i = 0; i < m; ++i) best_gain = max(best_gain, delta[i]);

        return base_valid + best_gain;
    }
};