/* Rotate Array 

[1,2,3,4,5,6,7], k = 3
 
[5,6,7,1,2,3,4]
 


*/

class Solution {
public:
    
    void rotatePointer(vector<int>& nums, int k) {
        
        /* Using extra memory O(n), O(n) */
        vector<int> temp = nums;
        int x = k % nums.size(); // Idx in which the rotated array starts with
        cout << x << endl;
        for(int i = 0; i < nums.size(); i++){
            int new_idx = (x+i)%nums.size();
            nums[new_idx] = temp[i];
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        
        /* Take Advantage of Reverse O(n), O(1) */
        
        /*
            [1,2,3,4,5,6,7], k = 3
            
            1. Reverse Entire Array
            [7,6,5,4,3,2,1], k = 3
            
            2. Reverse Two Subarrays, marked by k
            [5,6,7][1,2,3,4]
            
        
        */
        
        int x = k % nums.size();
        reverse(nums.begin(), nums.end());
        /*Reverse sub_arrays */
        reverse(nums.begin(), nums.begin()+x);
        reverse(nums.begin()+x, nums.end());
        
    }

};