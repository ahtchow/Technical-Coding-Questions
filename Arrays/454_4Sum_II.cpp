class Solution {
public:
    
    /*
    
    O(n^2) - time
    O(n^2) - space
    
    
    */
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int numTuple = 0;
        unordered_map<int, int> perm;
        
        /* For first two num list , count num of permutatio  of a sum */
        for(auto n1 : nums1){
            for(auto n2: nums2){
                perm[n1 + n2]++;
            }       
        }
        
        int sum;
        /* Check number of combinations that can be made */
        for(auto n3: nums3){    
            for(auto n4: nums4){
                sum = -(n3+n4);
                numTuple += perm[sum];
            }
        }
        
        return numTuple;
    }
};