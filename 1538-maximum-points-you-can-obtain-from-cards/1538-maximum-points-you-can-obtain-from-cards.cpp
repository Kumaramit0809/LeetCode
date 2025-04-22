class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int Lsum = 0, Rsum = 0, maxSum = 0;
        for(int i =0;i<k;i++){
            Lsum = Lsum+cardPoints[i];
            maxSum = Lsum;
        }
        int Rindex =n-1;
        for(int i = k-1;i>=0;i--){
            Lsum = Lsum -cardPoints[i];
            Rsum = Rsum + cardPoints[Rindex];
            Rindex = Rindex-1;

            maxSum = max(maxSum,Lsum+Rsum);

        }
        return maxSum;
    }
};