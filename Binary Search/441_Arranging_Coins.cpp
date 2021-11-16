class Solution {
public:
    int arrangeCoins(int n) {
        int num_rows = 0;
        int req = 1;
        int num_coins = n;
        
        while(true){
            if(num_coins >= req){
                num_coins -= req;
                num_rows ++;
            } else{
                break;
            }
            req++;
        }
        return num_rows;
    }
};