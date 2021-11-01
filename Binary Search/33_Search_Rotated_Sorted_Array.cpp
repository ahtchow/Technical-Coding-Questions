class Solution {

    
/*

O(log(n))
O(1)

Assumptions: No repeating number

0 	1	2	 3	  4	  5	  6	  7	 8	 9

[45 61, 71, 72 , 73, 0 , 1, 21, 33, 37]

L				 M 					 R

Indx: (0+9)/2 = 4
- arr[M] > arr[L] : sorted and increasing
        - if target in between arr[L] to arr[M]
            then explore left
        - if not in range:
                then explore right
				
- else the right must be sorted: e.g


0 	1	2	 3	  4	  5	  6	  7	  8	   9

[61, 71, 72, 73 , 0,  1, 21,  33, 37, 45]

L				  M 					 R

        - if target in between arr[M] to arr[R]
            then explore right
        - if not in range:
                then explore left		


*/    
    
public:
    int search(vector<int>& nums, int target) {
        
        int mn = 0;
        int mx = nums.size()-1;
        int val, md;
        while(mn<=mx){
            
            md = (mn + mx)/2;
            val = nums[md];
            
            if(val == target){
                return md;
            } else if (nums[mn] <= nums[md]){ /* left is sorted and increasing */
                
                if(target>=nums[mn] && target<nums[md]){ /* Number is left of us */
                    mx = md-1;
                } else{
                    mn = md+1;
                    
                }

            } else{ /* right is sorted and increasing */
                
                if(target>nums[md] && target<=nums[mx]){ /* Number is right of us */
                    mn = md+1;
                } else{
                    mx = md-1;
                }

            }
            
        }
        return -1;
    }
};