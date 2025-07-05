class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i: arr){
            map[i]++;
        }
        int ans = -1;
        for(auto it:map){
            if(it.first==it.second) ans=max(ans,it.first);
        }
        return ans;
    }
};