class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int minVal = INT_MAX;

        for (int b : basket1) {
            freq[b]++;
            minVal = min(minVal, b);
        }
        for (int b : basket2) {
            freq[b]--;
            minVal = min(minVal, b);
        }
        vector<int> surplus;
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1;
            int half = abs(count) / 2;
            for (int i = 0; i < half; ++i) {
                surplus.push_back(fruit);
            }
        }
        sort(surplus.begin(), surplus.end());
        long long cost = 0;
        int n = surplus.size();
        for (int i = 0; i < n / 2; ++i) {
            cost += min(2 * minVal, surplus[i]);
        }

        return cost;
    }
};