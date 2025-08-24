class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int cz = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                cz++;
            while (cz > 1) {
                if (nums[j] == 0)
                    cz -= 1;
                j++;
            }
            ans = max(ans, i - j);
        }
        return ans;
    }
};