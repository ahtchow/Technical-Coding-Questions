class Solution {
public:
    
    /*
    
    O(N) - Time 
    O(N) - Space
    
    [1,0,0,0,1,0,1]
    ans = 1
    K = 2 
    
    */
    
    int maxDistToClosestDp(vector<int>& seats) {
        vector<int> dp(seats.size(), INT_MAX);
        int maxDist = 0;
        int currDist = -1;

        /* Left pass */
        for(int i = 0; i < seats.size(); i++){

            if(seats[i]){
                dp[i] = 0;
                currDist = 0;
            } else if(currDist != -1){
                currDist++;
                dp[i] = min(dp[i],currDist);
                
            }
        
        }
        currDist = -1;
        /* right pass */
        for(int i = seats.size()-1; i >=0; i--){

            if(seats[i]){
                dp[i] = 0;
                currDist = 0;
            }  else if(currDist != -1){
                currDist++;
                dp[i] = min(dp[i],currDist);
            }
        
        }
        
        for(int i = 0; i < seats.size(); i++){
            cout << dp[i] << endl;
            maxDist = max(dp[i], maxDist);
        
        }
        
        return maxDist;
    }
    
    int maxDistToClosest(vector<int>& seats) {

        int maxDist = 0;
        int last_chair = -1;
        
        /* In this approach, we only remember the last 
        time we saw a chair and we took the middle as the distance 
        
        O(n), O(1)
        
        */
        
        for(int i=0; i < seats.size(); i++){
            if (seats[i] == 1){
                if(last_chair == -1){
                    /* initialize max distance as dist from start to chair */
                    maxDist = i;
                }
                else{
                    maxDist = max(maxDist, (i-last_chair)/2);
                }
                last_chair = i;
            }
        }
        
        /* If there is only one chair - consider distance between chair and end*/
        maxDist = max(maxDist, int(seats.size())-1-last_chair);
        
        return maxDist;
    }
};