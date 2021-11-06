class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int _min = prices[0];
        for(int i = 1; i < prices.size(); i++){
            max_profit = max(max_profit, prices[i]-_min);
            _min = min(prices[i], _min);
        }
        
        return max_profit;
    }
};