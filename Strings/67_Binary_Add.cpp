class Solution {
public:
    
    /*
    
    a - '11'
    b - '01'
    ---------
       '100'
    
    O(n) - Runtime if n is length of string
    O(n) - space for string length
    
    */
    
    
    string addBinary(string a, string b) {
        string result;
        int a_len = a.size() - 1;
        int b_len = b.size() - 1;
        int carry = 0;
        string ans;
        
        /* Consider the string in reverse order
         
         Make sure we processed all bits and there is no carry over left
        
        */
        while(a_len >= 0 || b_len >= 0 || carry > 0 ){

            if(a_len >= 0){
                carry += a[a_len] - '0';
                
                a_len--;
            }
             
            if(b_len >= 0){
                carry += b[b_len] - '0';
                b_len--;
            }
            
            ans += carry % 2 +'0';
            carry /= 2;

        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};