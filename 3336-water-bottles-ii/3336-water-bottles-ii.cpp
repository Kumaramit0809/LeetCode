class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;

        while (numBottles >= numExchange) {
            totalDrunk += numExchange;
            numBottles -= numExchange;
            numExchange++;
            numBottles++;
        }

        return totalDrunk + numBottles;
    }
};