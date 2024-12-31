class Solution {
public:
    int myAtoi(string s) {
        // for whitespace
        int i = 0;
        long ans = 0;
        while(i<s.length() && isspace(s[i])){
            i++;
        }
        // for empty sring
        if(s.length()==0)return 0;

        // for signedness
        bool neg = false;
        if(s[i] == '-'){
            neg = true;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
 
        // for conversion/numeric 
        while(i<s.length()&&s[i] >= '0' && s[i] <= '9'){
            int  digit = s[i] - '0';
            ans = ans * 10 + digit;


            // for rounding/overflow
            if (!neg && ans > INT_MAX) return INT_MAX;
            if (neg && -ans < INT_MIN) return INT_MIN;

            i++;
        }
        if (neg) ans = -ans;

        return static_cast<int>(ans);   
    }
};