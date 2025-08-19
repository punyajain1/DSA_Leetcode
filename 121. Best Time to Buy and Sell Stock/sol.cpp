class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=0;
        int d=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[mini]>prices[i]){
                mini=i;
            }
            d=max(d,(prices[i]-prices[mini]));
        }
        return d;
    }
};
