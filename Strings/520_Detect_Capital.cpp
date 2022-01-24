class Solution {
public:

    /* Uppercase Alphabet: 65-90 */
    bool isUpperCase(const char &c){
        return c >=65 && c <=90;
    }
      
    bool detectCapitalUse(string word) {
        int num_cap = 0;
        
        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i])){
                num_cap++;
            }
        }
        
        /* All caps or beginning just caps */
        if(num_cap == word.size() || 
           (num_cap == 1 && isUpperCase(word[0])) ||
           num_cap == 0 ){
            return true;
        }
        
        return false;
    }
};