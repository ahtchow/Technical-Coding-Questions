class Solution {
public:
    
    
    /*
    
    OG: 
        1   2   3
        
        4   5   6
        
        7`  8   9
        
    Transpose: 
        1   4   7
        
        2   5   8
        
        3`  6   9
    
    Reverse: 
        7   4   1
        
        8   5   2
        
        9`  6   3
    
    */
    
    /* Reverse on Diagonal - Transpose */
    void transpose(vector<vector<int>> & matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    /* Reverse on L to R */
    void reverse(vector<vector<int>> & matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            int l = 0;
            int j = n - 1;
            while(l<j) {
                swap(matrix[i][l], matrix[i][j]);
                l++;
                j--;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        /* Rotate = Transpose, then Transpose (Order Matters) */
        transpose(matrix);
        reverse(matrix);

    }
};