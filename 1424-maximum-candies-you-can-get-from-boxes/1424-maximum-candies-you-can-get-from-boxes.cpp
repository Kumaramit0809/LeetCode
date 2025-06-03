class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans=0;
        set<int>hb;
        set<int>hk;
        queue<int>q;
        for(auto x:initialBoxes){
            if(status[x]==1)
            q.push(x);
            else{
                hb.insert(x);
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans+=candies[it];
            for(auto x:keys[it]){
                hk.insert(x);
            }
            for(auto x:containedBoxes[it]){
                if(status[x]==1 || hk.find(x)!=hk.end()){
                    q.push(x);
                }
                else{
                    hb.insert(x);
                }
            }
            for(auto x:hb){
                if(hk.find(x)!=hk.end()){
                    q.push(x);
                    hb.erase(x);
                }
            }
        }
        return ans;
    }
};