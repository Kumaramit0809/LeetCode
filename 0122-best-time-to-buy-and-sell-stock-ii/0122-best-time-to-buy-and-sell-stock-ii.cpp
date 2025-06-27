class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit_made = 0;
        for(int i = 1 ; i < n ; i++){
            if(prices[i] > prices[i-1]){
                profit_made += (prices[i] - prices[i-1]);
            }
        }
        return profit_made;
    }
};