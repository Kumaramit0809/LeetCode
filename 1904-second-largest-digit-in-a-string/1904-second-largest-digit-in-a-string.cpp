class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int secondLargest = -1;
        int n = s.size();

        for (char c : s) {
            if (isdigit(c)) {
                int num = c - '0';
                if (num > largest) {
                    secondLargest = largest;
                    largest = num;

                } else if (num > secondLargest && num != largest) {
                    secondLargest = num;
                }
            }
            
        }
        return secondLargest;
    }
};