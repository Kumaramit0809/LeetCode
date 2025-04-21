class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int>& candidates, int idx, int target, vector<int>& arr) {
        // Base Case
        if (target == 0) {
            res.push_back(arr);
            return;
        }
        if (idx == candidates.size())
            return;

        if (candidates[idx] <= target) {
            // we can pick
            arr.push_back(candidates[idx]);
            f(candidates, idx + 1, target - candidates[idx], arr);
            arr.pop_back();
        }
        // not pick
        int j = idx + 1;
        while (j < candidates.size() && candidates[j] == candidates[j - 1]) {
            j++;
        }
        f(candidates, j, target, arr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> arr;
        f(candidates, 0, target, arr);
        return res;
    }
};