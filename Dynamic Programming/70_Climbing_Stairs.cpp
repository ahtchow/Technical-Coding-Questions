class Solution {
public:
    
    /*
        
    1   2   3   4   5  
    
    1   2   3   5   8
        
    How many situations lead up to being able to arrive to level X, Ans. X-1 + X-2

    O(N) - time & space
        
    */
    
    
    vector<int> memo;
    
    int helper(vector<int> & memo, int n){
        if (memo[n] != 0){
            return memo[n];
        }
        
        memo[n] = helper(memo, n-1) + helper(memo, n-2);
        return memo[n];
        
    }
    
    int climbStairs(int n) {
        
        vector<int> memo(n+1);

        if(n == 1 || n == 2){
            return n;
        }

        memo[1] = 1;
        memo[2] = 2;
        
        
        
        return helper(memo, n);
    }
};