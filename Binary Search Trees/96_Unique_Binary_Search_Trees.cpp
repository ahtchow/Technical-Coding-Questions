class Solution {
public:
    /*
    
    For 1: 1 BST
    
    For 2: 2 BST
    
    For 3: [1,2,3] : 5 BST
        - Rooted at 1: 2 BST
        - Rooted at 2: 1 BST
        - Rooted at 3: 2 BST
    
    For 4: [1,2,3,4] : 14
        - Rooted at 1: 5 BST (1x5)
        - Rooted at 2: 2 BST (1x2)
        - Rooted at 3: 2 BST (2x1)
        - Rooted at 4: 5 BST (5x1)


    Optimal: O(n^2) time, O(n) space

    O(n^2) time - For each value up to n, we have to solve the amount of BST subproblem which takes O(n)
    O(n) space - For DP array.
        
    */

    int solve(int n, vector<int> &dp){
        
        /* If Number Of Values to Left or Right is <= 1 */
        if(n <= 1) return 1;
        
        /* If we have solved this subset of problem 
        already return answer */
        if(dp[n] != -1) return dp[n]; 
        
        int res = 0;
        for(int i = 1; i <= n; i++){
            int nums_to_right = n-i;
            int nums_to_left = i-1;
            res += solve(nums_to_left, dp) * solve(nums_to_right, dp);
        }
        
        dp[n] = res;
        return dp[n];
        
        
    }

    int numTrees(int n) {
        
        vector<int>dp(n+1,-1);
        return solve(n, dp);

    }
};