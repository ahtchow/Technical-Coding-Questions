class Solution {
public:
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        string empty = ".";
        char a = empty[0];
        /* Validate Each Row */
        for(int r = 0; r < N; r++){
            unordered_set<char> seen;
            int numbers_seen = 0;
            for(int c = 0; c < N; c++){
                if(board[r][c] != a){
                    numbers_seen++;    
                    seen.insert(board[r][c]);
                } 
            }
            
            if(seen.size() != numbers_seen){
                return false;
            }
        }
        
        /* Validate Each Col */
        for(int c = 0; c < N; c++){
            unordered_set<char> seen;
            int numbers_seen = 0;
            for(int r = 0; r < N; r++){
                if(board[r][c] != a){
                    numbers_seen++;    
                    seen.insert(board[r][c]);
                } 
            }
            
            if(seen.size() != numbers_seen){
                return false;
            }
        }
        
        /* Validate Each 3x3 */
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,0}, {0,1}, {0,-1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
        for(int r = 1; r < N; r = r+3){
            for(int c = 1; c < N; c = c+3){
                unordered_set<char> seen;
                int numbers_seen = 0;
                for(auto dir: directions){
                    int rx = r + dir[0];
                    int cx = c + dir[1];
                    if(board[rx][cx] != a){
                        numbers_seen++;    
                        seen.insert(board[rx][cx]);
                    } 
                    
                }
                if(seen.size() != numbers_seen){
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
};