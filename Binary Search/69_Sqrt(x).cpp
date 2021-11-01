class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
     
    long int mn = 2;
    long int mx = x;
    long int md, val;
    while(mn<=mx){
        md = (mn+mx)/2;
        val = md * md;
        if(val == x){
            return md;
        } else if(val < x){
            /* too small */
            mn = md + 1;
        } else{
            mx = md - 1;
        }
        
    }
    
    return mx;
        
    }
};