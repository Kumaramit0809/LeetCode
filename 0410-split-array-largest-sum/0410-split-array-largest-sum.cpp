class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        if (nums.size() == k)
            return *max_element(nums.begin(), nums.end());
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int subCount = 1;
            int subSum = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] + subSum <= mid)
                    subSum += nums[i];
                else {
                    subCount++;
                    subSum = nums[i];
                }
            }
            if (subCount > k) {

                start = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};