class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans(cost.size());
        for (int i = 0; i < ans.size(); i++)
            ans[i] = min((i ? ans[i - 1] : INT_MAX), cost[i]);
        return ans;
    }
};