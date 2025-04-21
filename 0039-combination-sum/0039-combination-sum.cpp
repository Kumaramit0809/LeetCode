class Solution {
public:
    void solve(vector<int> arr, int sum, int idx, vector<vector<int>>& ans,
               vector<int> temp) {
        if (sum == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx >= arr.size() || sum < 0) {

            return;
        }
        temp.push_back(arr[idx]);

        solve(arr, sum - arr[idx], idx, ans, temp);
        temp.pop_back();

        solve(arr, sum, idx + 1, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> temp;
        int idx = 0;
        vector<vector<int>> ans;
        solve(arr, target, idx, ans, temp);
        return ans;
    }
};