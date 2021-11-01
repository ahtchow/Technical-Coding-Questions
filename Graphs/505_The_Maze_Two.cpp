class Solution {
public:
    
    const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};

    /**
     * @brief
     * Time complexity : O(m*n*max(m,n)). Complete traversal of maze 
     *                   will be done in the worst case. 
     * Space complexity : O(mn). distancedistance array of size m*n is used.
     * Optimal: Using Priority Queue w BFS to see which path is cheapest and explore those ones.
     */

    /* BFS */
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        int min_dist = INT_MAX;
        /* Assume start and destination in the same place */
        deque<vector<int>> queue;
        queue.push_back({start[0], start[1], 0});
        vector<vector<int>> cost_map(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        cost_map[start[0]][start[1]] = 0;

        while(!queue.empty()){
            vector<int> curr = queue.front();
            queue.pop_front();
            
            for(auto dir : directions){
                int new_row = curr[0];
                int new_col = curr[1];
                int new_dist = 0;
                while(new_col+dir[1] >= 0 && new_col+dir[1] < maze[0].size() &&
                      new_row+dir[0] >= 0 && new_row+dir[0] < maze.size() &&
                      maze[new_row+dir[0]][new_col+dir[1]] == 0){
                    new_row = new_row+dir[0];
                    new_col = new_col+dir[1];
                    new_dist += 1;
                }
                if(curr[2] + new_dist < cost_map[new_row][new_col]){
                   queue.push_back({new_row, new_col, curr[2] + new_dist});
                   cost_map[new_row][new_col] = curr[2] + new_dist;
                }
            }


        }
         

        return cost_map[destination[0]][destination[1]] < INT_MAX ? cost_map[destination[0]][destination[1]] : -1;
        
        
    }
};