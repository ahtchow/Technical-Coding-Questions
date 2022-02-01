class Solution {
public:
    
    
    /*
    
    Find cheapest cost to move from there
    
    Input: cost = [1,   100,    1,  1,  1,  100,    1   ,1  ,100    ,1]
    min_cost to move from       
                   1    100     2   3   3   104     4    5   105     6   
    
    
    
    O(n) - Time
    O(n) - space
    */ 
    
    
    
    
    
    int helper(const vector<int> &cost, vector<int> &costToMoveFrom, int n){
        
        if (costToMoveFrom[n] != -1){
            return costToMoveFrom[n];
        }
        
        costToMoveFrom[n] = min(helper(cost, costToMoveFrom, n-1), helper(cost, costToMoveFrom, n-2)) + cost[n];
        return costToMoveFrom[n];
        
    }
    
    
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        vector<int>costToMoveFrom(n, -1);
        
        if(n == 1 || n == 2){
            return min(cost[0], cost[1]);
        } else{
            costToMoveFrom[0] = cost[0];
            costToMoveFrom[1] = cost[1];
        }
        
        helper(cost, costToMoveFrom, n-1);
        return min(costToMoveFrom[n-1], costToMoveFrom[n-2]);
        
        
    }
    
    
};