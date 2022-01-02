class Solution {
public:
    /*
    
    Optimal: O(n) time, O(n) space
    
    Alternative: O(n^2), O(1) space
    
    */    
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int pairs = 0;
        
        /* Store how many times we see a modulod length of a song */
        unordered_map<int,int> freq;
        
        for(auto t: time){
            int required_t = (60-(t%60)); 
            pairs += freq[required_t%60]; /* Modulo by 60 for the case that remainder (60-t%60)=60. */
            freq[t%60]+=1;
        }
        
        
        return pairs;
    }
};