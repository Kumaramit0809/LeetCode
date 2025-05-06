class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            arr.push_back(nums[nums[i]]);
        }
        return arr;
    }
};