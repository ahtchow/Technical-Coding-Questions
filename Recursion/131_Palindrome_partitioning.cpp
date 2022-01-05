class Solution {
public:
    
    
    /**
    
    Backtracking - Permutation 
    
                        [a,a,b]
                        
                    /      |        \
                    
                [a]       [aa]      [aab]
            
             /     \       |          
            
          [a]      [ab]   [b]       
    
          /
    
        [b] 

    
    
    O(n * 2^n) - checking if palindrome + permutations(backtracking)
    O(2^n) - space
    
    
    
    **/
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> p_vec;
        vector<string> vec;
        partition_helper(s, p_vec, vec, 0);
        
        return p_vec;
    }
    
    
    void partition_helper(const string s, vector<vector<string>> & p_vec, vector<string> curr_perm, int idx){
        
        if(idx == s.size()){
            
            if(curr_perm.size()>0){
                p_vec.push_back(curr_perm);
            }
            
            return;
            
        } 
        
        else{
            
            for(int i = idx; i < s.size(); i++){
                if (is_palindrome(s, idx, i)){
                    curr_perm.push_back(s.substr(idx,i-idx+1));
                    partition_helper(s, p_vec, curr_perm, i+1);
                    curr_perm.pop_back();
                }
                
            }
        }
        
        return;
    }
    
    
    
    bool is_palindrome(string p, int i, int j){
        
        while(i<=j){
            
            if(p[i] != p[j]){
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
    
};