class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
         if(n==0) return 0;
        int i=0;
        for(int num:nums){
            if(i==0 || num>nums[i-1]){
                nums[i++]=num;
            }
        }
        return i;
    }
};