class Solution {
public:
    
    /* Dynamic Programming to Find Unique Paths
    
    - Can only move down and right at any given moment
    
    E.g 
    
        0   1   2   3   4
    0   1   1   1   1   1
    1   1   
    2   1
    3   1
    4   1                  <-- Goal
        
    Note: You can only go to those locations one way bcs of R/D movement
    
    
        0   1   2   3   4
    0   1   1   1   1   1
    1   1   2   3   4   5
    2   1   
    3   1
    4   1                  <-- Goal
            
    Note: Add idx above and idx left to find num of paths to curr loc.
    
        0   1   2   3   4
    0   1   1   1   1   1
    1   1   2   3   4   5
    2   1   3   6   10  15  
    3   1   4   10  20  35
    4   1   5   15  35  70  <-- Goal    
    
    
    */
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp_table(m, vector<int>(n, 1));
        
        for(int col = 1; col < m; col++){
            for(int row = 1; row < n; row++){
                dp_table[col][row] = dp_table[col-1][row]+dp_table[col][row-1];
            }
            
        }
        
        return dp_table[m-1][n-1];
        
    }
};