/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    /*
    
    Runtime: O(N)
    Space: O(H)
    
    */
    
    void sumRootToLeafHelper(TreeNode* node, vector<int> nums, int & ans){

        nums.push_back(node->val);
        if(!node->left && !node->right){
            int bit = 0;
            for(int i = nums.size()-1; i >= 0; i--){
                if(nums[i]){
                    ans += pow(2, bit);
                }
                bit++;
            }
            return;
        }
        
        
        if(node->left){
            sumRootToLeafHelper(node->left, nums, ans);
        }
        if(node->right){
            sumRootToLeafHelper(node->right, nums, ans);
        }

    }
    
    void sumRootToLeafHelperOptimized(TreeNode* node, int cur, int & ans){

        cur = cur*2+node->val; /* Trick to make sure exponents are multiplied correctly*/
        if(!node->left && !node->right){
            ans += cur;
            return;
        }
        
        
        if(node->left){
            sumRootToLeafHelperOptimized(node->left, cur, ans);
        }
        if(node->right){
            sumRootToLeafHelperOptimized(node->right, cur, ans);
        }

    }
    
    
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        sumRootToLeafHelperOptimized(root, 0, ans);
        return ans;
    }
};