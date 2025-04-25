class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int cnt= func(nums, goal)-func(nums, goal-1);
       return cnt;
    }
    int func(vector<int>&nums, int goal){
         if(goal<0)return 0;
        int n=nums.size();
        int left=0, right=0;
        long long sum=0;
        int cnt=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
};