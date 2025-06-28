class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeroCount = 0, n = nums.size();
        vector<int> result(n, 0);
        
        for (int num : nums) {
            if (num == 0) zeroCount++;
            else product *= num;
        }
        if (zeroCount > 1) return result; 
        if (zeroCount == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) result[i] = product;
            }
        } else {
            for (int i = 0; i < n; i++) {
                result[i] = product / nums[i];
            }
        }

        return result;
    }
};