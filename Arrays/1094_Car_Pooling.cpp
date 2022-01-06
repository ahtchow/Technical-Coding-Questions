class Solution {
public:
    
    /**
     *  Time: O(nlog(n))
     *  Space: O(2n)
     * 
     */
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        /* Store action at each stop */ 
        vector<pair<int, int>> actions;
        for(auto trip: trips){

            /* Drop Off Up */
            actions.push_back(pair<int,int>(trip[2], -trip[0]));
            
            
            /* Pick Up */
            actions.push_back(pair<int,int>(trip[1], trip[0]));
            
        }
        
        /* Sorting ensures that drop off occurs before pick up */
        sort(actions.begin(), actions.end());
        
        
        int seats = capacity;
        for(auto action: actions){
            
            cout << action.first << " " << action.second << endl;

            seats -= action.second;
            if(seats < 0){
                return false;
            }
            
        }
        
        return true;
        
    }
};