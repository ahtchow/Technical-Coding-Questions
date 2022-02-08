class Solution {
public:
    
    /*
    
    
       Bottom Up - O(n) time, O(1) space
    
    
    */

    int robBU(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        nums[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++){
            nums[i] = max(nums[i-2] + nums[i], nums[i-1]);
        }
        
        return nums[nums.size()-1];
        
    }
    
    
    int helper(const vector<int> & nums, vector<int> &memo, int n){
        
        if(memo[n] != -1){
            return memo[n];
        }

        memo[n] = max(helper(nums, memo, n-2) + nums[n], helper(nums, memo, n-1));
        return memo[n];
    }
    
    int rob(vector<int>& nums) {
        /*

        Top Down: O(n), O(n)

        */
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> memo(nums.size(), -1);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        return helper(nums, memo, nums.size()-1);
        
    }
};