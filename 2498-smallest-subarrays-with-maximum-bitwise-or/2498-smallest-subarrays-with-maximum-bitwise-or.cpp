class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeenBit(32, -1);
        vector<int> result(n);

        for (int i = n - 1; i >= 0; i--) {

            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    lastSeenBit[bit] = i;
                }
            }

            int maxReach = i;

            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeenBit[bit] != -1) {
                    maxReach = max(maxReach, lastSeenBit[bit]);
                }
            }

            result[i] = maxReach - i + 1;
        }

        return result;
    }
};