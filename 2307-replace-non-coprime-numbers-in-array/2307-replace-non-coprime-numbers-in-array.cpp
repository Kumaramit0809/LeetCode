class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.push_back(nums[i]);

            while (st.size() >= 2) {
                long long int x = st[st.size() - 1];
                long long int y = st[st.size() - 2];
                long long int gcf = gcd(x, y);
                if (gcf == 1)
                    break; // no need to merge and continue with original
                else {
                    st.pop_back();
                    st.pop_back();
                    long long int lcm = (x * y) / gcf;
                    st.push_back(lcm);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < st.size(); i++) {
            ans.push_back((int)st[i]);
        }
        return ans;
    }
};