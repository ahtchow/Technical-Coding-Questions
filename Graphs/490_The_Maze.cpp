class Solution {
public:
    
    const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};
    
//    Runtime: O(wxh) - must travcerse entire matrix
//    Space: O(wxh) - up to wxh recursive calls 

    void DFS(const vector<vector<int>>& maze, 
             vector<vector<int>>& visited, 
             const vector<int>& destination, 
             vector<int> coord, 
             bool &found){
        
        if(coord == destination){
            found = true;
            return;
        }
        
        int row = coord[0];
        int col = coord[1];
        visited[row][col] = 1;
                
        /* Find Next Positions for: Up, Down, Left, Right */
        
        int new_row;
        int new_col;
        for(auto dir : directions){
            new_row = row;
            new_col = col;
            
            while(new_col+dir[1] >= 0 && new_col+dir[1] < maze[0].size() &&
                  new_row+dir[0] >= 0 && new_row+dir[0] < maze.size() &&
                  maze[new_row+dir[0]][new_col+dir[1]] == 0){
                new_row = new_row+dir[0];
                new_col = new_col+dir[1];  
            }
            if(visited[new_row][new_col] != 1){
                DFS(maze, visited, destination, {new_row, new_col}, found);
            }
            
        }
              
        return;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        /* Assume start and destination in the same place */
        
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
        bool found = false; 
        /* Perform DFS, until all options have been explored*/
        DFS(maze, visited, destination, start, found);
        return found;
        
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        /* Assume start and destination in the same place */
        
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
        bool found = false; 
        /* Perform DFS, until all options have been explored*/
        DFS(maze, visited, destination, start, found);
        return found;
        
    }

     /* BFS */
     bool hasPathBFS(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        /* Assume start and destination in the same place */
        deque<vector<int>> queue;
        queue.push_back(start);
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
         
        while(!queue.empty()){
            vector<int> curr = queue.front();
            queue.pop_front();
            visited[curr[0]][curr[1]] = 1;
            if(curr == destination){
                return true;
            }
            for(auto dir : directions){
                int new_row = curr[0];
                int new_col = curr[1];

                while(new_col+dir[1] >= 0 && new_col+dir[1] < maze[0].size() &&
                      new_row+dir[0] >= 0 && new_row+dir[0] < maze.size() &&
                      maze[new_row+dir[0]][new_col+dir[1]] == 0){
                    new_row = new_row+dir[0];
                    new_col = new_col+dir[1];  
                }
                if(visited[new_row][new_col] != 1){
                   queue.push_back({new_row, new_col});
                }
            }


        }
         

        return false;
        
};