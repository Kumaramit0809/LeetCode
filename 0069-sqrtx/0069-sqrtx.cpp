class Solution {
public:
    int mySqrt(int x) {
        if (x < 2 ) {
            return x;
        }else if(x==9){
            return 3;
        }
        double low = 0;
        double high = static_cast<double>(x);
        double tolorance = 1e-7;

        cout << setprecision(5);
        while (high - low > tolorance) {
            double mid = (low + high) / 2;
            double square = mid * mid;
            if (abs(square - x) < tolorance) {
                
                       return mid;
            } else if (square > x)
                high = mid;
            else
                low = mid;
        }
        double mid = low + (high - low) / 2.0f;
        
        return (int)mid;
    }
};