class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums2(n, 0); 
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            nums2[i] = nums[i];
        }

        sort(nums2.begin(), nums2.end());
        unordered_map<int, int> map;
        int i = n - 1;
        while (k--) {
            map[nums2[i--]]++;
        }

        for (int i = 0; i < n; i++) {
            if (map.find(nums[i]) != map.end() && map[nums[i]] > 0) {
                ans.push_back(nums[i]);
                map[nums[i]]--;
            }
        }
        
        return ans;
    }
};