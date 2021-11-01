class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r){
            int m = (l+r)/2;
            
            /* This is the pivot point*/
            if(nums[m]>nums[m+1]){
                return nums[m+1];
            }
            
            if(nums[m] > nums[0]){
                l = m+1;
            } else{
                r = m;
            }
        }
        
        /* Case where the array is not shifted */
        if(nums[l] > nums[0]) return nums[0];
        return nums[l];
    
            
    }
};