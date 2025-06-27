class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int bi =0;bi< 1 << n ;bi++){
            ans.push_back(bi ^ (bi>>1));
        }
        return ans;
    }
};