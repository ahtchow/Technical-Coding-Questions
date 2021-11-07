    /* Dynamic Programming to Find Unique Paths
    
    - Can only move down and right at any given moment, 1 marks object
    - Naive Create a DP
    
    E.g 
    
        0   1   2   3   4
    0   0   0   1   0   0
    1   0   0   0   0   0
    2   1   0   0   1   0
    3   0   0   0   0   0
    4   0   0   0   0   0  <-- Goal
        
    Note: You must calculate the initial table, if we hit the obj stop
    
    
        0   1   2   3   4
    0   1   1   1   0   0
    1   1   2   3   3   3
    2   1   3   6   0   3
    3   0   3   9   9   12
    4   0   3   12  21  42  <-- Goal
            
    Note: Start from 1 to m, 1 to n
    If: the idx value is 1 then change to 0 and move on
    Else: Add idx above and idx left to find num of paths to curr loc.  
    
    Edge Case: object in starting location
    
    Naive: O(nxm), O(nxm) space
    Optimal: O(nxm) time, O(1) space
    
    */

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        /* utilizing obstacleGrid as dp array */
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        /* Edge Case:Starting on Obstacle */
        if(obstacleGrid[0][0]) return 0;
                
        vector<vector<int>> dp_array(m,vector<int>(n, 1));
        
        /* Check first col for obstacles */
        bool found_obs = false;
        for(int col = 0; col < n; col++){
            if(obstacleGrid[0][col] == 1){
               found_obs = true;
            }
            if(found_obs) dp_array[0][col] = 0;
        }
            
        /* Check first row for obstacles */
        found_obs = false;
        for(int row = 1; row < m; row++){

            if(obstacleGrid[row][0] == 1){
               found_obs = true;
            }
            if(found_obs) dp_array[row][0] = 0;
        }
        
        /* DP */
        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                if(obstacleGrid[row][col] == 1){
                    dp_array[row][col] = 0;
                }else{
                    dp_array[row][col] = dp_array[row-1][col] + dp_array[row][col-1];
                }
            }
        }
        
        return dp_array[m-1][n-1];

    int uniquePathsWithObstaclesInPlace(vector<vector<int>>& obstacleGrid) {
        
        /* utilizing obstacleGrid as dp array */
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        /* Edge Case:Starting on Obstacle */
        if(obstacleGrid[0][0]) return 0;
        
        /* Check first col for obstacles */
        bool found_obs = false;
        for(int col = 0; col < n; col++){
            if(obstacleGrid[0][col] == 1){
               found_obs = true;
            }
            if(found_obs){
                obstacleGrid[0][col] = 0;
            } else{
                obstacleGrid[0][col] = 1;
            }  
        }
            
        /* Check first row for obstacles */
        found_obs = false;
        for(int row = 1; row < m; row++){

            if(obstacleGrid[row][0] == 1){
               found_obs = true;
            }
        
            if(found_obs){
                obstacleGrid[row][0] = 0;
            } else{
                obstacleGrid[row][0] = 1;
            }  
        }
        
        /* DP */
        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                if(obstacleGrid[row][col] == 1){
                    obstacleGrid[row][col] = 0;
                }else{
                    obstacleGrid[row][col] = obstacleGrid[row-1][col] + obstacleGrid[row][col-1];
                }
            }
        }
        
        return obstacleGrid[m-1][n-1];
    }
};