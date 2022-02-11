class Solution {
public:

    /*

    O(n) - Linear sliding window scan
    O(1) - Constant Space 

    */
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()){
            return false;
        }
        
        unordered_map<char,int> hm1, hm2;
        
        for(char c : s1){
            hm1[c]++;
        }
        

        /* Sliding Window */
        int l = 0;
        int r = l+s1.size()-1;
        bool contains = false;

        for(char c: s2.substr(l, r-l+1)){
           hm2[c]++;            
        }
        
        
        while(r < s2.size()){
            contains = true;
            for(auto pair: hm1){
                if(hm2[pair.first] != pair.second){
                    contains = false;
                }                  
            }

            if(contains){
                return true;
            }

            r++;
            hm2[s2[l]]--;
            hm2[s2[r]]++;
            l++;

        }
        
        return false;
        
        
    }
};