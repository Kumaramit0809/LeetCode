class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int  n = nums.size();
        
        
        int sum_index = n;
        int sum_arr = 0;
        for(int i =0;i<n;i++) {
            sum_index += i;
            sum_arr += nums[i];
         
        }
        return (sum_index - sum_arr);
        
        
    }
};