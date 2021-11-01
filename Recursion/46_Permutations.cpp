class Solution {
public:
    
    /**                 
                            [1,2,3]
                          / 
                  [1,2,3] -- [1,3,2]
                /   
        [1,2,3] -- [2,1,3] -- [2,1,3], [2,3,1]
                \
                 [3,2,1] - [3,2,1], [3,1,2]   
                    
                    
        Backtracking:
                
        
        
    
    **/
    
    void formPermutations(vector<int>& nums, vector<vector<int>> &permutations, int nums_added){
        
        /* Base Case */
        if(nums_added == nums.size()){
            permutations.push_back(nums); /* Make copy */
        }
        
        for(int i = nums_added; i < nums.size(); i++){
            swap(nums[nums_added], nums[i]);
            formPermutations(nums, permutations, nums_added+1);
            swap(nums[nums_added], nums[i]);
            
        }
        
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> permutations;
    
        formPermutations(nums, permutations, 0);
        return permutations;
        
        
        
    }
};