class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sellPrice = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > minPrice){
                sellPrice = max(sellPrice, prices[i] - minPrice);
            }else{
                minPrice = prices[i];
            }
        }
        return sellPrice;
    }
};
