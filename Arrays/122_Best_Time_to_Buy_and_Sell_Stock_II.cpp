class Solution {
public:
    
    /*

    [7,1,5,3,6,4] A:7
        
    O(n) - time
    O(1) - space
    
    We are not limited on the number of transactions, so simply
    check nexts day price and see whether to buy and sell the next day.
    Do not buy if the next day does not have any problems.
        
    
    */
    
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i+1]>prices[i]){
                profit += prices[i+1]-prices[i];
            }

        }
        return profit;
        
    }
};