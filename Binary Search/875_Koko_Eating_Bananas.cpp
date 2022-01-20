class Solution {
public:
    
    /*
    
    KoKo Eating Bananas:
    - Koko can decide her bananas-per-hour eating speed of k
    -  Each hour, she chooses some pile of bananas and eats k bananas from that pile.
    -  If the pile has less than k bananas, she eats all of them instead 
         and will not eat any more bananas during this hour.
    - Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
    
    Return: minimum integer k such that she can eat all the bananas within h hours

    piles = [3,6,7,11], h = 8
    
    speed_range [1, 11]
        mid: 6, hours 3 -> [1, 6]
        mid: 3, hours 10 -> [4, 6]
        mid: 5, hours 8 -> [4, 5]
        mid: 4, hours 8 -> [4, 4] -> break; return 4.


    O(n) - Time
    O(1) - Space

    */
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        /* The optimal speed is between [1, max num of bananas in a pile] */
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while(left < right){
            
            int speed = (left+right)/2;
            int hours_spent = 0;
            
            for(int pile:piles){
            /* division is round down, so add 1 if there is remainder */
                hours_spent += (pile / speed) + (pile % speed != 0);
            }
            
            if(hours_spent > h){
                /* We are eating too slow*/
                left = speed+1;
            }else{
                /* We are eating too fast*/
                right = speed;
            }
        }
        
        /* Return right as it is the minimum speed we eat all the bananas within h hours. */
        return right;
    }
};