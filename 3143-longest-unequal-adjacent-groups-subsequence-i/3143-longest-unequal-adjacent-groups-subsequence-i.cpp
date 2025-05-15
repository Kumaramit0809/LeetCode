class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size();
        vector<string>ans;
        ans.push_back(words[0]);
        int i=0,j=0;
        while(j<n){
            if(groups[i]==groups[j]) j++;
            else{
                ans.push_back(words[j]);
                i=j;
            }
        }
        return ans;
    }
};