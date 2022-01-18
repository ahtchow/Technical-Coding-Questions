class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int canPlace = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            
            if(canPlace == n){
                return true;
            }  
            /* Check Left */
            if(i-1 >= 0 && flowerbed[i-1] != 0){
                continue;
            }
            /* Check Right */
            if(i+1 < flowerbed.size() && flowerbed[i+1] != 0){
                continue;
            }
                
            if(flowerbed[i] == 0){
                canPlace++;
                flowerbed[i] = 1;
            }
            
            if(canPlace >= n){
                return true;
            }

        }
        
        return false;
        
    }
};