class Solution {

    /**
     * @brief w/ Memoization DP , better than recursion
     *  Time: O(3N) ~ O(N)
     *  Space:  O(N), 
     *
     *            
     *  Memo { 3: 2, 
     *         4: 3,
     *         5, 5 }
     *           
     */


public:
    unordered_map<int,int> memo;
    int tribonacci(int n) {
        if(memo.find(n) != memo.end()){
            return memo[n];
        } 
        
        if(n == 1 || n == 2){
            return 1;
        }
            
        if(n == 0){
            return 0;
        }
        
        memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return memo[n];
        
    }
    

};