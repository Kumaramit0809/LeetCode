class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd1 = (n + 1) / 2;
        long long even1 = n / 2;
        long long odd2 = (m + 1) / 2;
        long long even2 = m / 2;
        return odd1 * even2 + odd2 * even1;
    }
};