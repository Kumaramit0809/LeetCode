class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;

        int val = 0;

        for (auto x : nums) {
            val = ((val * 2) + x) % 5;

            if (val == 0)
                ans.push_back(true);

            else
                ans.push_back(false);
        }

        return ans;
    }
};