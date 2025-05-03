class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        auto findMinimumRotation = [&](int front, bool isTop, bool isSwaped) {
            int rotate = isSwaped ? 1 : 0;

            for (int i = 1; i < n; i++) {
                int curr = isTop ? tops[i] : bottoms[i];

                if (curr != front) {
                    int oppoCurr = isTop ? bottoms[i] : tops[i];

                    if (oppoCurr == front)
                        rotate++;
                    else {
                        rotate = 1e9;
                        break;
                    }
                }
            }

            return rotate;
        };

        int minRotate = min({findMinimumRotation(tops[0], true, false),
                             findMinimumRotation(bottoms[0], true, true),
                             findMinimumRotation(bottoms[0], false, false),
                             findMinimumRotation(tops[0], false, true)});

        return minRotate >= n ? -1 : minRotate;
    }
};