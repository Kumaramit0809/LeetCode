class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxD = sqrt(pow(dimensions[0][0], 2) + pow(dimensions[0][1], 2));
        int maxA = dimensions[0][0] * dimensions[0][1];

        for (int i = 1; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            double d = sqrt(l * l + b * b);
            int a = l * b;

            if (d > maxD) {
                maxD = d;
                maxA = a;
            } else if (fabs(d - maxD) <1e-9) { 
                maxA = max(maxA, a);
            }
        }
        return maxA;
    }
};