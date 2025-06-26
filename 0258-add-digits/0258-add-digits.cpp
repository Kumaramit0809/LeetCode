class Solution {
public:
    int addDigits(int num) {
        int prev = num % 10;
    num /= 10;

    while (num > 0) 
    {
        int digit = num % 10;
        num /= 10;
        int result = digit + prev;
        if (result >= 10) 
        {
            digit = result % 10;
            result /= 10;
            prev = digit + (result % 10);
        } 
        else
            prev = result;
    }
    return prev;
    }
};