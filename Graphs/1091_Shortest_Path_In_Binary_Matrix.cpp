class Solution {
public:
    
    vector<vector<int>> directions = {{-1,-1}, {-1, 0}, {-1, 1}, {1, 0}, {1, -1}, {1, 1} , {0, 1}, {0, -1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        vector<int> target = {int(grid.size()-1), int(grid[0].size())-1, 0};
        if(grid[0][0] == 1 || grid[target[0]][target[1]] == 1){
            return -1;
        }
        
        /* When start is finish */
        if(0 == target[0] || 0 == target[1]){
            return 1;
        }
        
        vector<vector<int>> cost_map(grid.size(), vector<int>(grid.size(), INT_MAX));
        deque<vector<int>> BFS_queue;
        BFS_queue.push_back({0,0,1}); // row, col, cost

        
        int min_dist = 0;
        
        while(!BFS_queue.empty()){
            vector<int> curr_loc = BFS_queue.front();
            BFS_queue.pop_front();
            int r = curr_loc[0];
            int c = curr_loc[1];
            int cost = curr_loc[2];
            for(auto dir: directions){
                
                /* boundary check */
                if(r+dir[0] >= 0 && r+dir[0] < grid.size() &&
                   c+dir[1] >= 0 && c+dir[1] < grid[0].size() && grid[r+dir[0]][c+dir[1]] == 0){
                    if(cost+1 < cost_map[r+dir[0]][c+dir[1]]){
                        /* if cost is less than prexisting cost, explore */
                        BFS_queue.push_back({r+dir[0], c+dir[1], cost+1});
                        cost_map[r+dir[0]][c+dir[1]] = cost+1;
                    }
                    

                }

            }
        
        }
        
        if(cost_map[target[0]][target[1]] > (target[0]+1) * (target[1]+1)){
            cout << cost_map[target[0]][target[1]] << endl;
            return -1;
        }
        
        return cost_map[target[0]][target[1]] < INT_MAX ? cost_map[target[0]][target[1]] : -1;
        
        
    }
};