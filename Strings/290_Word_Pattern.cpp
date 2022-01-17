class Solution {
public:
    
    /**
    
    O(n) - where n is the number of characters in string s
    O(m) - hashmap that scales with number of char in pattern
    
    
    **/
    
    bool eval_word(char a, string curr_s, 
                   unordered_map<string,char> &string_to_pattern, 
                   unordered_map<char,string> &pattern_to_string){
        
        /* Does this mapping exist */
        if(pattern_to_string.find(a) == pattern_to_string.end() && 
           string_to_pattern.find(curr_s) == string_to_pattern.end()){
            pattern_to_string[a] = curr_s;
            string_to_pattern[curr_s] = a;
        }
        else{
            
           /* Is the existing mapping incorrect */ 
           if(pattern_to_string[a] != curr_s || string_to_pattern[curr_s] != a){
              return false;
           }
        }
        
        return true;
        
    }
    
    
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> pattern_to_string;
        unordered_map<string,char> string_to_pattern;
        string curr_s;
        int pat_it = 0;
        /* Allow check for last word at end of loop */
        s.push_back(' ');
        
        for(int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                
                if(!eval_word(pattern[pat_it], curr_s, string_to_pattern, pattern_to_string)){
                    return false;
                }

                pat_it++;
                curr_s.clear();
                
            } else{
                curr_s.push_back(s[i]);
            }
            
        }
        
        
        if(pattern.size() != pat_it){
            return false;
        }

        return true;
    }
};