class Solution {
public:
    /**
     * @brief 
     *  Runtime: O(WxN)
     *  Space: O(WxN)
     * 
     */
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        /* Count number of fresh */
        int fresh = 0;
        int row = grid.size();
        int col = grid[0].size();
        deque<vector<int>> rotten;
        
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 1){
                    fresh++;
                } else if(grid[r][c] == 2){
                    rotten.push_back({r,c,0});
                }
            }
        }
        
        int minutes = 0;
        
        while(!rotten.empty()){
            
            vector<int> curr_rotten = rotten.front();
            rotten.pop_front();
            int r = curr_rotten[0];
            int c = curr_rotten[1];
            minutes = curr_rotten[2];
            if(grid[r][c] == 2){

                /*update state */
                for(auto dir: directions){

                    /* boundary check */
                    if(r+dir[0] >= 0 && r+dir[0] < row &&
                       c+dir[1] >= 0 && c+dir[1] < col && grid[r+dir[0]][c+dir[1]] == 1){
                        grid[r+dir[0]][c+dir[1]] = 2;                                       
                        fresh--;
                        rotten.push_back({r+dir[0],c+dir[1], minutes+1});
                    }
                }
                                

            }
          

            
        }
        
        if(fresh > 0){
            return -1;
        }
        else{
            return minutes;
        }

        
        
        
        
    }
};