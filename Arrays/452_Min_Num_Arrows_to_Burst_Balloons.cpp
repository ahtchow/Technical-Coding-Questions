class Solution {
public:
    
    /*

    [[10,16],[2,8],[1,6],[7,12]]
    [1,6], [2,8], [7,12], [10,16]
    
    Type of overlap:
    
    ------
        ------
        
    ----------
       ----
    
    Ballons : 4
    Min Arrows Required: 1
    Overlap: pt[i][0] < pt[i-1][1]
    
    
    Vis:
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    -----------
      -------------  
                -------------
                       ------------------
                       
    Runtime: O(n)
    Space: O(1)

    */
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        
        if(points.size() <= 1){
            return points.size();
        }
        

        sort(points.begin(), points.end(), [](vector<int>& a,vector<int>& b){
            return a[1]< b[1];
        });
        
        int prevEnd = points[0][1];
        int arrows = 1; /* At best we need one arrow to pop all balloons
        
        /* For loop used to calculate how many addition arrows we need based on overlap */
        for(int i = 1; i < points.size(); i++) {
            
            /* Condition Overlap */
            if(points[i][0] <= prevEnd){
                continue;
            }
            
            /* If the overlap stops, we need an additional arrow */
            arrows++;
            prevEnd = points[i][1];
            
        }
        
        return arrows;
    }
};