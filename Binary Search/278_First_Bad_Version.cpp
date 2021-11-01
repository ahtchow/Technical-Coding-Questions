// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    /*  g g b b b b
        1 2 3 4 5 6
        L M R     
        
        - return M if M+1 good and M bad 

        return 4;
    
    
    */
        
    
    
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while(l< r){
            int mid = l+(r-l)/2;
            if(isBadVersion(mid)){
                r = mid;
            }else{
                l = mid+1;
            }        
        
        
        }
        
        return l;
        
    }
};