class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       
        vector <int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0;i<nums1.size();i++){
            
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    
                    // ans.push_back(nums1[i]);
                    bool alreadyAdded = false;
                    for (int k = 0; k < ans.size(); k++) {
                        if (ans[k] == nums1[i]) {
                            alreadyAdded = true;
                            break;
                        }
                    }
                    if (!alreadyAdded) {
                        ans.push_back(nums1[i]);
                    nums2[j] =INT_MIN;
                    break;
                }
            }
        }
        }
        return ans;
        
    }
};