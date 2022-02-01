class Solution {
public:
    
    /**
     * @brief w/ Memoization DP , better than recursion
     *  Time: O(2N) ~ O(N)
     *  Space:  O(N), 
     * 
     *                              9
     *                            8   7   
     *                          7  6 
     *                         6  5  
     *                        5  4
     *                       4  3
     *                      3  2 
     *                     2  1
     *            
     *  Memo { 3: 2, 
     *         4: 3,
     *         5, 5 }
     *           
     */


    unordered_map<int, int> memo;
    int fib(int n) {
        if(memo.find(n) != memo.end()){
            return memo[n];
        } 
        
        if(n == 1 || n == 2){
            return 1;
        }
            
        if(n == 0){
            return 0;
        }
        
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
        
    }
};