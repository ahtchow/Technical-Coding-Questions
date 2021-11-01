class Solution {
public:
    
    /*
        -2 1 -3 4 -1 2 1 -5 4
        P
        
        curr_sum: max(P, P+curr_sum) -> is it better to start over or add onto subarray?
        abs_sum: max(abs_sum, curr_sum)
        if curr_sum becomes less than 0, we know to restart the contigous subarray.
        
        O(n)
        O(1)
     
    */
        
        
    
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int abs_sum = INT_MIN;
        
        for(int i = 0 ; i < nums.size(); i++){
            curr_sum = max(nums[i], curr_sum+nums[i]);
            abs_sum = max(abs_sum, curr_sum);
        
        }
        return abs_sum;
        
    }
};