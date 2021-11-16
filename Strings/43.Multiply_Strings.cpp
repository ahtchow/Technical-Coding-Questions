class Solution {
public:
    
    /**
    
    Algorithm: O(MN), Space(M+N)
    
     1. Multiply
        
            1   2   3
        x   4   5   6
        ______________
    5   6   0   8   8
      
     6 [100 + 20 + 3] + 50[100 + 20 +3] + 400[100 + 20 +3]
     = 5 6 0 8 8
     
     2. Code It
    
    */
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0"){
            return "0";
        }
        
        int ans_len = num1.size() + num2.size();
        vector<int> ans(ans_len, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                int digit = (num1[i] - '0') * (num2[j]- '0');
                ans[i + j] += digit;
                /* Handle Carry Over */
                ans[i + j + 1] += ans[i + j]/10;             
                ans[i + j] = ans[i + j] % 10;
            }
        }
        
        /*  At this point solution is in reverse order:
            Remove Leading Zeros & Reverse */

        for(int i = ans.size()-1; i >= 0; i--){
            if(ans[i] == 0){
                ans.pop_back();
            } else{
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        
        string ans_char(ans.size(), '0');
        int i = 0;
        for(auto a : ans){
            char digit = '0' + a;
            ans_char[i] = digit;
            i++;
        }
        
        return ans_char;
    }
};