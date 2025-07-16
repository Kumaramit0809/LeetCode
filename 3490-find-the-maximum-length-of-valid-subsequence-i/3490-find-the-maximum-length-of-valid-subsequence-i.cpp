class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int allEven = 0, allOdd = 0, oddEven = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                allEven++;
            } else {
                allOdd++;
            }
        }

        bool expectOdd = true;
        bool expectEven = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && expectEven) {
                oddEven++;
                expectEven = false;
                expectOdd = true;
            } else if (nums[i] % 2 != 0 && expectOdd) {
                oddEven++;
                expectOdd = false;
                expectEven = true;
            }
        }

        return max({allEven, allOdd, oddEven});
    }
};