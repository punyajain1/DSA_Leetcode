class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0;
        while(numBottles >= numExchange){
            int i=numBottles/numExchange;
            cnt+=numExchange*i;
            numBottles-=numExchange*i;
            numBottles+=i;

        }
        return cnt + numBottles;

    }
};