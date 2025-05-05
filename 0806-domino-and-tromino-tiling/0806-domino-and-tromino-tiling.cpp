class Solution {
public:
    int mod=1e9+7;
    int f(int &n,int ind,int fill, vector<vector<int>> &dp){
        if(ind==n){
            if(fill==0) return 1;
            return 0;
        }
        if(ind>n) return 0;
        if(dp[fill][ind]!=-1) return dp[fill][ind]%mod;
        long long possibilities=0;
        if(fill==0){
            possibilities += f(n,ind+1,fill,dp);
            possibilities%=mod;
            possibilities += f(n,ind+2,fill,dp);
            possibilities%=mod;
            possibilities += 2*f(n,ind+1,1,dp);
            possibilities%=mod;
        }
        else {
            possibilities += f(n,ind+1,1,dp);
            possibilities%=mod;
            possibilities += f(n,ind+2,0,dp);
            possibilities%=mod;
        }
        return dp[fill][ind]=(possibilities)%mod;
    }
    int numTilings(int n) {
        vector<vector<int>> dp(2,vector<int>(n+1,-1));
        return f(n,0,0,dp);
    }
};