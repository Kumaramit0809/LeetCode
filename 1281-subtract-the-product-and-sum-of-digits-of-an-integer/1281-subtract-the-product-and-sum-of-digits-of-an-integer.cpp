class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
         while(n!= 0){
            int rem = n%10;
            product = product * rem;
            sum = sum + rem;

            n = n/10;
         }
         return product - sum;
    }
};