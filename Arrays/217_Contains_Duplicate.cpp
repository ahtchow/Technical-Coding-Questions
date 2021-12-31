class Solution {
public:
    bool containsDuplicateSort(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // nlog(n);
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        
        return false;
                    
    }
    
    
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        
        for(auto num: nums){
            if(set.find(num) != set.end()){
                return true;
            } else{
                set.insert(num);
            }
        }
       
        
        return false;
        
    }
};