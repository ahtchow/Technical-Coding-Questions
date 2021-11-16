class Solution {
public:
    
    /**
    
    Naive: Hashmap
    O(n) - time;
    O(n) - space
    
    Optimal:Bit Manipulation
    
    **/
    vector<int> singleNumberSet(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> ret;
        for(auto num: nums){
            if(seen.find(num) == seen.end()){
                /* First time seeing */
                seen.insert(num);
            } else{
                /* Second time seeing */
                seen.erase(num);
            }
        }
        for(auto num: seen){
             ret.push_back(num);
        }
        
        return ret;
    }
    
    /*
    
    E.g  [1, 2, 2, 3, 3, 4]
    
    In Bit Form: [001, 010, 010, 011, 011, 100]
    
    XOR Each Bit:
        - Start with 0: 000
        - XOR with the num and set the operator to the result
    
    So the state of the Operator will be:
        000 ^ 001 = 001
        001 ^ 010 = 011
        011 ^ 010 = 001
        001 ^ 011 = 010
        010 ^ 011 = 001
        001 ^ 100 = 101
    
    Result: 101 (5)
    
    Num1 ^ Num2 = 101
    
    For each bit: [1,0,1]
      
    ... Man this is hard, never learn this.
    
    
    */
    
    vector<int> singleNumber(vector<int>& nums) {
        long int XOR = 0;
        for(auto n : nums){
            XOR = XOR ^ n;
        }
        
        /* XOR = num1 ^ num2 */
        long int x = (XOR & (XOR-1));
        long int firstbit = x ^ XOR;
        long int num1 = 0;
        
        for(auto n:nums){
            if (n & firstbit){
                num1 = num1 ^ n;
            }
        }
        return {int(num1), int(num1 ^ XOR)};
 
    }
};