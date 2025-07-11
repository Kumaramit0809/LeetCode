class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        sort(m.begin(), m.end());
        vector<long long> v(
            n, 0);
        long long last = 0;
        vector<long long> meet(n, 0); 
        for (auto x : m) {
            long long int a = x[0];
            long long int b = x[1];

            long long int y = 100000000000000000;
            long long int j = n;
            long long int k;
            for (int i = 0; i < n; i++) {

                if (meet[i] <= a &&
                    j > i) { 
                    j = i;
                    break;
                }
                if (meet[i] <
                    y) {
                    y = meet[i];
                    k = i;
                }
            }

            if (j == n) {
                j = k;
            }
            v[j]++; 
            if (meet[j] < a) {
                meet[j] = b; 
            } else
                meet[j] += b - a;
        }
        long long int j;
        long long int y = INT_MIN;
        for(int i=0;i<n;i++){
            if (v[i] > y) {
                y = v[i];
                j = i;
            }
        }
        return j;
    }
};