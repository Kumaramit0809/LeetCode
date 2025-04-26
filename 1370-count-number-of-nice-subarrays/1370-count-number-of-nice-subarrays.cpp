class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, a = -1, b = -1, n = nums.size();
        int cnt =0;        
        int ans = 0;
 
        while (cnt < k && i < n) {
            if (nums[i] % 2 == 1) { 
                cnt++;              
                if (b == -1)        
                    b = i;
            }
            i++;
        }

        
        if (cnt < k)
            return 0;
        
        ans = b - a;

        while (i < n) {
            if (nums[i] % 2 == 1) { 
                a = b;              
                b++;
                while (b < n) {
                    if (nums[b] % 2 == 1) 
                        break;
                    b++;
                }
            }
            ans += b - a;
            i++;
        }
        return ans;
    }
};