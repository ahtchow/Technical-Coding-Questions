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

    /* 
    
    O(n) number of nodes
    O(n) number of nodes

    */
public:
    
    bool DFS(TreeNode* tree, int min_val, int max_val){

        if(!tree) return true;
        
        if(tree->val >= max_val || tree->val <= min_val){
            return false;
        }
        
        bool left_valid = DFS(tree->left, min_val, tree->val);
        bool right_valid = DFS(tree->right, tree->val, max_val);
        return left_valid && right_valid;
        
        
    }
    
    bool isValidBST(TreeNode* root) {
                
        return DFS(root, INT_MIN, INT_MAX);
    
        
    }
};