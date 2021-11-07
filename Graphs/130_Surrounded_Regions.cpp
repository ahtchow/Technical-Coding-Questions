class Solution {
public:

    /*
        O(n) time, O(n) space
    */
    
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
    
    void DFS(vector<vector<char>>& board, vector<vector<bool>> & visited, pair<int,int> coord, const bool flip){
        
        visited[coord.first][coord.second] = true;
        
        if(flip){
            board[coord.first][coord.second] = 'X';
        }
        
        int m = board.size();
        int n = board[0].size();
        
        
        for(auto dir: directions){
            pair<int, int> new_coord;
            new_coord.first = coord.first + dir[0];
            new_coord.second = coord.second + dir[1];
            
            /* Boundary check */
            if(new_coord.first >= 0 && new_coord.second >= 0 &&
               new_coord.first < m && new_coord.second < n &&
               board[new_coord.first][new_coord.second] == 'O' &&
               !visited[new_coord.first][new_coord.second]){
                
                DFS(board, visited, new_coord, flip);
                
            }
             
        }
        
        
        
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        /* Unique Cases */
        if(m < 3 && n < 3) return;
        
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        /* First Visit the Border of Board - DFS, don't flip & mark visited. */
        for(int col = 0; col < n; col++){
            if(board[0][col] == 'O' && !visited[0][col]){
                DFS(board, visited, pair<int,int>(0, col), false);
            }
            if(board[m-1][col] == 'O' && !visited[m-1][col]){
                DFS(board, visited, pair<int,int>(m-1, col), false);
            }
        }
        for(int row = 0; row < m; row++){
            if(board[row][0] == 'O' && !visited[row][0]){
                DFS(board, visited, pair<int,int>(row, 0), false);
            }
            if(board[row][n-1] == 'O' && !visited[row][n-1]){
                DFS(board, visited, pair<int,int>(row, n-1), false);
            }
        }
        
        /* Flip regions that are surrounded - exclude border */
        for(int row = 1; row < m-1; row++){
            for(int col = 1; col < n-1; col++){
                if(board[row][col] == 'O' && !visited[row][col]){
                    DFS(board, visited, pair<int,int>(row, col), true);
                }
            }
        }
                
    }
};