class Solution {
public:
    
    
    /*
    
        Input: nums = [1,1,1,2,2,3]        
        Output: 5, nums = [1,1,2,2,3,_]
    
        O(n) - time, O(1) - space
    
    */
    
    
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() < 3){
            return nums.size();
        }
        
        int k = nums.size();
        int p = 2;
        
        while(p < k){
            
            bool erased = false;
            if(nums[p] == nums[p-2]){
                cout << k << endl;
                nums.erase(nums.begin()+p);
                erased = true;
            }
            
            k = nums.size();
            if(!erased){
                p++;
            }
        
        }
        
        
        return k;
        
        
    }
};