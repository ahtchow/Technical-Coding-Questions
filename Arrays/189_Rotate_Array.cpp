class Solution {
public:
    
    /*
    
    Optimal: O(n) time, O(1) space
    [1,2,3,4,5,6,7], k =1
    [7,6,5,4,3,2,1], reverse entire nums
    [7,6,5|4,3,2,1] , mark before kth indx
    [5,6,7|1,2,3,4] , reverse from both sides
    
    */
    
    
    void reverse(vector<int> &nums, int i, int j){
        while(i < j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int a = k % nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, a-1);
        reverse(nums, a, nums.size()-1);
        
    }
};