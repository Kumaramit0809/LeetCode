class Solution {
public:
    string largestGoodInteger(string num) {
        char ret = 0;
        for(size_t i = 0; i < num.length()-2; ++i)
            if(num[i] == num[i+1] && num[i] == num[i+2])
                ret = max(ret, num[i]);
        return ret == 0 ? "" : string(3, ret);
    }
};