class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int upper = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() - 1;
        if(lower < nums.size() && nums[lower] == target){
            return {lower, upper};
        }
        return {-1, -1};
        
        
    }
};