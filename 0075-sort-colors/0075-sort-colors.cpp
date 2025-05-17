class Solution {    
public:
    void sortColors(vector<int>& nums) {
        //count sort? so O(n)
        int n = nums.size();
        int c0 = 0,c1 = 0,c2 = 0;
        for(int x : nums){
            if(x == 0)c0++;
            else if(x == 1)c1++;
            else c2++;
        }
        int i = 0;
        for(int j = 0 ; j < c0 ; i++,j++)nums[i] = 0;
        for(int j = 0 ; j < c1 ; i++,j++)nums[i] = 1;
        for(int j = 0 ; j < c2 ; i++,j++)nums[i] = 2;
        return ;
    }
};