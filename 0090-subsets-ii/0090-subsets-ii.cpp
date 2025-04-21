class Solution {
    int n;
    vector<vector<int>> ans;
    void backtrack(int ind, vector<int>& ds, vector<int>& nums) {
        ans.push_back(ds);
        for (int i = ind; i < n; i++) {
            
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            
            ds.push_back(nums[i]);     
            backtrack(i + 1, ds, nums); 
            ds.pop_back();              
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        n = nums.size();
        sort(nums.begin(),
             nums.end()); 
        vector<int> ds;
        int ind = 0;
        backtrack(ind, ds, nums);
        return ans;
    }
};