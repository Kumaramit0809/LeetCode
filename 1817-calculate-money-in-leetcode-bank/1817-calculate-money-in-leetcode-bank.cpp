class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int weekStart = 1; 
        int day = 0;

        while (n > 0) {
            for (int i = 0; i < 7 && n > 0; i++) {
                sum += weekStart + i; 
                n--;
            }
            weekStart++; 
        }

        return sum;
    }
};