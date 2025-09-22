class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int maxFreq = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (seen.count(nums[i]))
                continue;
            seen.insert(nums[i]);
            int freq = 0;
            for (int j = 0; j < n; ++j)
                if (nums[j] == nums[i])
                    ++freq;
            if (freq > maxFreq) {
                maxFreq = freq;
                ans = freq;
            } else if (freq == maxFreq) {
                ans += freq;
            }
        }
        return ans;
    }
};