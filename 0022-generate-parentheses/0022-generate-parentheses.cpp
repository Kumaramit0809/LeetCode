class Solution {
private:
    void solve(int open, int close, int n, string& temp, vector<string>& ans) {
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (open <= close && open > 0) {
            temp += '(';
            solve(open - 1, close, n, temp, ans);
            temp.pop_back();
        }
        if (close > open && close > 0) {
            temp += ')';
            solve(open, close - 1, n, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        solve(n, n, n, temp, ans);
        return ans;
    }
};