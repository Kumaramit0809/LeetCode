class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        for(int i=0;i<n;i++){
            if(dominoes[i][0]>dominoes[i][1]){
                swap(dominoes[i][0],dominoes[i][1]);
            }
        }

        sort(dominoes.begin(),dominoes.end());
        map<vector<int>,int> map;

        for(vector<int>& x:dominoes){
            map[x]++;
        }

        int count=0;
        for(pair<vector<int>,int> p:map){
            count+=(p.second*(p.second-1)/2);
        }

        return count;
    }
};