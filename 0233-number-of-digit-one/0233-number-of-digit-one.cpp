class Solution {
public:
    int countDigitOne(int n) {
        long pv = 1; 
        long left, cur, right;
        int ans = 0;

        while (true) {
            cur = (n / pv) % 10;    
            left = n / (pv * 10);   
            right = n % pv;         

            if (cur == 0) {
                ans += (left * pv);
            } else if (cur == 1) {
                ans += (left * pv) + (right + 1);
            } else {
                ans += (left + 1) * pv;
            }

            pv *= 10;               
            if (pv > n) break;     
        }

        return ans;
    }
};