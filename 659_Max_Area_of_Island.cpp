class Solution {
public:
    
    /**
    
    Runtime: O(wxh) - must travcerse entire matrix
    Space: O(wxh) - up to wxh recursive calls 
    
    **/
    
    struct Coordinate{
        int col;
        int row;
    };
    
    int getSizeOfIsland(vector<vector<int>>& grid, 
                        int &size,
                        const Coordinate location){
        
        grid[location.col][location.row] = -1;
        size++;
        
        /* Check Left */
        if(location.col-1 >= 0 && grid[location.col-1][location.row] == 1){
            getSizeOfIsland(grid, size, Coordinate{location.col-1, location.row});
        }

        /* Check Right */
        if(location.col+1 < grid.size() && grid[location.col+1][location.row] == 1){
            getSizeOfIsland(grid, size, Coordinate{location.col+1, location.row});
        }
        
        /* Check Up */
        if(location.row-1 >= 0 && grid[location.col][location.row-1] == 1){
            getSizeOfIsland(grid, size, Coordinate{location.col, location.row-1});
        }
        
        /* Check Down */
        if(location.row+1 < grid[0].size() && grid[location.col][location.row+1] == 1){
            getSizeOfIsland(grid, size, Coordinate{location.col, location.row+1});
        }        
        return size;
    }
    
    void printIsland(const vector<vector<int>>& grid){
        
        for(int col = 0; col < grid.size(); col++){
            for(int row = 0; row < grid[0].size(); row++){
                cout << grid[col][row] << " ";
            }
            cout << endl;
        }
    
    
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_size = 0;
        for(int col = 0; col < grid.size(); col++){
            for(int row = 0; row < grid[0].size(); row++){
                if(grid[col][row] == 1){
                    int size = 0;
                    getSizeOfIsland(grid, size, Coordinate{col, row});
                    max_size = size > max_size ? size : max_size;
                }
            
            }
        }
        
        return max_size;
    }
};