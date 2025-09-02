class Solution {
public:
    int numberOfPairs(vector<vector<int>>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (nums[i][0] >= nums[j][0] && nums[i][1] <= nums[j][1]) {
                    bool hasPointInside = false;

                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            int x = nums[k][0], y = nums[k][1];
                            int x1 = nums[j][0], y1 = nums[j][1];
                            int x2 = nums[i][0], y2 = nums[i][1];

                            if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                                hasPointInside = true;
                                break;
                            }
                        }
                    }

                    if (!hasPointInside) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};