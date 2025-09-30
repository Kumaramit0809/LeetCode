class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() != 1) {
            vector<int> vec;
            int n = nums.size();
            for (int i = 1; i < n; i++) {
                vec.push_back((nums[i - 1] + nums[i]) % 10);
            }
            nums = vec;
        }
        return nums[0];
    }
};