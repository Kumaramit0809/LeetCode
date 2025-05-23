class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int minChange = INT_MAX;
        int gainCount = 0;

        for (int num : nums) {
            int gain = (num ^ k) - num;
            if (gain > 0) {
                sum += (num ^ k);
                gainCount++;
                minChange = min(minChange, gain);
            } else {
                sum += num;
                minChange = min(minChange, -gain);
            }
        }

        
        if (gainCount % 2 == 1) {
            sum -= minChange;
        }

        return sum;
    }
};