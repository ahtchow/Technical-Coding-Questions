class Solution {
public:

    /*
        Runtime: log(n);
        Space: O(1);


    */
    int search(vector<int>& nums, int target) {
        int mn = 0;
        int mx = nums.size()-1;
        int guess, md;
        while(mn<=mx){
            md = (mn+mx)/2;
            guess = nums[md];
            if(guess == target){
                return md;
            } else if(guess < target){
                /* small */
                mn = md+1;
            } else{
                mx = md-1;
            }
            
        }
        
        return -1;
    }
};

