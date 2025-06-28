class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();

        if (n == 0)
            return result;

        int a = nums[0], b = nums[0];
        for (int i = 1; i < n; i++) {
            if (b + 1 == nums[i])
                b = nums[i];
            else {
                if (a == b)
                    result.push_back(to_string(a));
                else
                    result.push_back(to_string(a) + "->" + to_string(b));
                a = b = nums[i];
            }
        }
        if (a == b)
            result.push_back(to_string(a));
        else
            result.push_back(to_string(a) + "->" + to_string(b));
        return result;
    }
};