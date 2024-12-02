class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int prefixSum = 0;
        int odd = 0;
        int even =1;
        int count  = 0;
        const int MOD = 1e9 + 7;
        
        for (int i =0;i<n;i++){
            
            prefixSum += arr[i];
            if(prefixSum & 1){
                count+= even;
                odd++;
                
            }else{
                count += odd;
                even++;
            }
            count %= MOD;
        }
        return count;
    }
};