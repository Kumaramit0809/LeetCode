class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int currentSum = 0;
        int maxElement = nums[0];

        for (int num : nums) {
            maxElement = max(maxElement, num);
            if (num > 0 && !seen.count(num)) {
                currentSum += num;
                seen.insert(num);
            }
        }

        return currentSum == 0 ? maxElement : currentSum;
    }
};
