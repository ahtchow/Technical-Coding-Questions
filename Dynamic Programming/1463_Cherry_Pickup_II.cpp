class Solution {
public:
    /**
     * @brief 
     *  Time Complexity O(MN^2), where M is the column length and N is the Row Length.
     *                  The input possibiliies are M*N*N since there is two robots with different row states but same M states
     * 
     *  Space Complexity: O(MN^2), we have to memorize M*N*N possible results. 
     */


    const vector<int> dx = {-1,0,1};
    int R;
    int C;
    int dp[71][71][71];

    int cherryPickupHelper(const vector<vector<int>>& grid, int r_1, int r_2, int y){
        if(y == R){
            return 0;
        }
        
        /* Memoization - check cache*/
        if(dp[r_1][r_2][y]!=-1) return dp[r_1][r_2][y];

        
        /* Pickup cherry add score */
        int score = 0;
        if(r_1 != r_2){
            score += (grid[y][r_1] + grid[y][r_2]);
        }else{
            score += grid[y][r_1];
        }
        
        dp[r_1][r_2][y] = score;

        for(auto dx1: dx){
            
            int r_1_new = r_1 + dx1;
            
            if(r_1_new < C && r_1_new >= 0){
                
                for(auto dx2: dx){
                
                    int r_2_new = r_2 + dx2;
                    
                    if(r_2_new < C && r_2_new >= 0){
                        
                        dp[r_1][r_2][y] = max(dp[r_1][r_2][y], score+cherryPickupHelper(grid, r_1_new, r_2_new, y+1));
                        
                    }

                }
                
            }
        }
                
        return dp[r_1][r_2][y];
        
    }
        
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        R = grid.size();
        C = grid[0].size();      
        return cherryPickupHelper(grid, 0, C-1, 0);
    }
};