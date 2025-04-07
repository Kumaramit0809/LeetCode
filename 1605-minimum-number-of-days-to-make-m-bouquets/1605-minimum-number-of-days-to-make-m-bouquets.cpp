class Solution {
public:
    bool possible(vector<int>&bloomDay, int day, int r, int b) {
        int count = 0;
        int no_of_bouquets = 0;

        for (int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }else{
                no_of_bouquets +=(count/b);
                count = 0;
            }
        }
        no_of_bouquets += count/b;
        return no_of_bouquets >= r;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long value = m*1LL*k;

        if(value>bloomDay.size()) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0;i<bloomDay.size();i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);

        }

        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high = mid-1;

            }
            else{
                low = mid+1;
            }

        }
        return low;
    }
};