class Solution {
  public:
    int findLHS(vector<int>& nums) {
        ranges::sort(nums); 
        int n = nums.size();
        int l = 0, r = 0, len = 0;
        while (r < n) { 
            int diff = nums[r] - nums[l];
            if (diff == 1) { 
                len = max(len, r - l + 1); 
                r++;
            }
            else if (diff < 1) 
                r++;
            else 
                l++;
        }
        return len;
    }
};