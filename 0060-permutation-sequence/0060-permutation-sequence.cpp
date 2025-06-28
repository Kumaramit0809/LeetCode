class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        for (int i = 1; i <= n; i++) {
            ans += to_string(i); 
        }

        for (int i = 1; i < k; i++) {
            next_permutation(ans.begin(), ans.end()); 
        }
        return ans;
    }
};