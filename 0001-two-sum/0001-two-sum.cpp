class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>num;
        
        for(int i = 0;i<n;i++){
            int more = target - nums[i];
            if(num.find(more) != num.end()){
                return {num[more],i};
            }
            num[nums[i]] = i;
        }
        return {-1,-1};
    }
};