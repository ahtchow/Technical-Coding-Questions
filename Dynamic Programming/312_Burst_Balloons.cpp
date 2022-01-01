class Solution {
public:
    
    /* Optimal : O(n^3) Time , O(n^2) Space 
    
    - bursting ith balloon gives nums[i - 1] * nums[i] * nums[i + 1] coins
    - if i-1 or i+1 is out of bounds, consider it as a value of 1
    - find maximum coins that can be collected (find order to pop)
    
    Brute Force: Explore every possibility like a decision tree, O(n^n) time. Not optimal
    
    Optimal Approach: For each element in num, how much money do we get from popping it last.  
                    O(n^2) for each subarray, O(n) for iterating through each possibbility to pop last.
    
    */
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp_table(nums.size(), vector<int>(nums.size(),0));
        
        /* len denotes the size of the subarray we consider */
        for(int len = 1; len <= nums.size(); len++){
            
            /* l denote of left reference for subarray and range is controlled by len */
            for(int l=0; l <= nums.size()-len; l++){
                
                /* right reference */
                int r = l + len - 1;
                
                /* iterator for subarray from [l,r] in nums to see which index is popped last*/
                
                for(int it = l; it <= r; it++){
                
                
                    /* initial values for implicit left and right */
                    int implicit_left = 1;
                    int implicit_right = 1;

                    if(l!=0){
                        implicit_left = nums[l-1];
                    }
                    if(r!=nums.size()-1){
                        implicit_right = nums[r+1];
                    }
                    
                    /* Assuming we have already solved the left and right subarray in dp table */
                    int left_sa_max_coins = 0;
                    int right_sa_max_coins = 0;
                    
                    if(l!=it){ /* there is a subarray to left */
                        left_sa_max_coins = dp_table[l][it-1];
                    }
                    if(r!=it){ /* there is a subarray to right */
                        right_sa_max_coins = dp_table[it+1][r];
                    }                    
                    
                    int max_coin = right_sa_max_coins + left_sa_max_coins + ( implicit_left * nums[it] * implicit_right);
                    dp_table[l][r] = max(dp_table[l][r], max_coin);
                    
                }
                
                
            }
            
            
            
        }
        
        
        return dp_table[0][nums.size()-1];
    
    }
};