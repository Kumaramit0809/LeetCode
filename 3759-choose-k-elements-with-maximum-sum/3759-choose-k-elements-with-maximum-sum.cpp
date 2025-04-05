class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);
        vector<pair<int, int>> p;
        
        
        for (int i = 0; i < n; i++) {
            p.push_back({nums1[i], i});
        }
        
        sort(p.begin(), p.end());
        
        multiset<long long> ms; 
        long long sum = 0;
        int le = 0;
        
        for (int i = 0; i < n; i++) {
            int a = p[i].first; 
            int ind = p[i].second; 

            while (le < i && p[le].first < a) {
                long long val = nums2[p[le].second];
                
                if (ms.size() < k) { 
                    sum += val;
                    ms.insert(val);
                } else if (*ms.begin() < val) { 
                    sum -= *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(val);
                    sum += val;
                }
                le++;
            }
            
            ans[ind] = sum; 
        }
        
        return ans;
    }
};