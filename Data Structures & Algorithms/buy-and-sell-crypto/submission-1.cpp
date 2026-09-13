class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxP = 0;

        while(r < prices.size()){
            if(prices[l] < prices[r]){
                maxP = max(maxP, prices[r] - prices[l]);

            } else {
                //found better buy price
                l = r;
            }
            r++;
        }
        return maxP;

    }
};
