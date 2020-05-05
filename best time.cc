class Solution {
public:

    int maxProfit(vector<int>& prices) {
        if ( prices.size() <= 1) return 0;
       
        int profit = 0;
        int change = 0;
        for (int index = 1; index < prices.size(); ++index) {
            change = prices[index]-prices[index-1];
            profit += change > 0 ? change : 0;
        }
        
        return profit;
    }
};