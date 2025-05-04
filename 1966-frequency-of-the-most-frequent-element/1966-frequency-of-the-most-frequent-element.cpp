class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        sort(nums.begin(), nums.end());
        
        int maxFreq = 0;
        long long total = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;
            total += nums[right];

            while ((long long)nums[right] * (right - left + 1) - total > k) {
                freqMap[nums[left]]--;
                total -= nums[left];
                left++;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};
