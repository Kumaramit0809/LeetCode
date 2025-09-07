class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        int a = n / 2;
        for (int i = 0; i < n; i++) {
            if ((a - i) == 0) {
                if (n % 2 != 0)
                    arr.push_back(0);
                else {
                    arr.push_back(a - i - 1);
                    a = a - 1;
                }
            } else {
                arr.push_back(a - i);
            }
        }
        return arr;
    }
};