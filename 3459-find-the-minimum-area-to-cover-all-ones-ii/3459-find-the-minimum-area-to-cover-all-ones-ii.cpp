class Solution {
public:
    int minimumSum(vector<vector<int>>& A) {
        int res = INT_MAX;
        for (int rot = 0; rot < 4; rot++) {
            int n = A.size(), m = A[0].size();
            for (int i = 1; i < n; i++) {
                int a1 = minimumArea(A, 0, i, 0, m);
                if (a1 == 0)
                    continue;
                for (int j = 1; j < m; j++) {
                    int a2 = minimumArea(A, i, n, 0, j);
                    int a3 = minimumArea(A, i, n, j, m);
                    if (a2 && a3)
                        res = min(res, a1 + a2 + a3);
                }
                for (int i2 = i + 1; i2 < n; i2++) {
                    int a2 = minimumArea(A, i, i2, 0, m);
                    int a3 = minimumArea(A, i2, n, 0, m);
                    if (a2 && a3)
                        res = min(res, a1 + a2 + a3);
                }
            }
            A = rotate(A);
        }
        return res == INT_MAX ? 0 : res;
    }

private:
    int minimumArea(vector<vector<int>>& A, int r1, int r2, int c1, int c2) {
        int left = INT_MAX, right = -1, top = INT_MAX, bottom = -1;
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                if (A[i][j]) {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }
        if (right == -1)
            return 0; // no 1s
        return (right - left + 1) * (bottom - top + 1);
    }

    vector<vector<int>> rotate(const vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> B(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                B[j][n - 1 - i] = A[i][j];
        return B;
    }
};
